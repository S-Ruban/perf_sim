#include <iostream>
#include "cachesim.h"
#include "processor.h"
#include "simif.h"
#include "devices.h"
#include "mmu.h"
#include "sim.h"
#include <set>
#include "fesvr/elfloader.h"
#include "fesvr/memif.h"
#include "fesvr/htif_hexwriter.h"
#include "insn_list.h"
// #include "insns/addi.cc"

using namespace std;
class simif_t;

void print_cpu_state(state_t *state)
{
    for (int r = 0; r < 32; r++)
        printf("x%d: 0x%016x\n", r, state->XPR[r]);
    for (int f = 0; f < 32; f++)
        printf("f%d: 0x%016x\n", f, state->FPR[f]);
    auto cycle_count = state->mcycle;
    uint64_t pc = state->pc;
    printf("pc: 0x%016x\n", pc);
}

std::vector<std::pair<reg_t, abstract_mem_t *>> make_mems(const std::vector<mem_cfg_t> &layout)
{
    std::vector<std::pair<reg_t, abstract_mem_t *>> mems;
    mems.reserve(layout.size());
    for (const auto &cfg : layout)
    {
        mems.push_back(std::make_pair(cfg.get_base(), new mem_t(cfg.get_size())));
    }
    return mems;
}

int main()
{
    cache_sim_t *cst = new cache_sim_t(2, 4, 64, "L1D");
    cst->print_stats();
    const isa_parser_t *isa = new isa_parser_t("RV64GC", "M");
    const cfg_t *config = new cfg_t();
    simif_t *sim;
    FILE *logfile = fopen("log.txt", "w");
    std::ostream &os = std::cout;

    std::vector<std::pair<reg_t, abstract_mem_t *>> mems = make_mems(config->mem_layout);
    std::vector<device_factory_t *> plugin_device_factories;
    vector<string> args;
    debug_module_config_t dm_config;
    sim_t *s = new sim_t(config, false, mems, plugin_device_factories, args, dm_config, "/home/rubans/perf_sim/perf_sim.log", false, "/home/rubans/perf_sim/perf_sim.dtb", false, logfile);

    processor_t *cpu = new processor_t(isa, config, s, 0, true, logfile, os);
    unsigned int cpu_xlen = cpu->get_const_xlen();
    unsigned int cpu_flen = cpu->get_flen();
    set<string> extensions = isa->get_extensions();
    mmu_t *mmu = cpu->get_mmu();
    state_t *state = cpu->get_state();
    printf("cpu_xlen = %d\n", cpu_xlen);
    printf("cpu_flen = %d\n", cpu_flen);
    printf("Extensions: ");
    for (string e : extensions)
    {
        string ext = e;
        printf("%s, ", ext);
    }
    printf("\n");
    htif_hexwriter_t htif(2048, 1024, 1024);
    memif_t memif(&htif);
    reg_t start_pc;
    map<string, uint64_t> elf = load_elf("test.elf", &memif, &start_pc, 64);
    target_endian<uint32_t> start_ib = memif.read_uint32(0x1011a);
    uint32_t ib = start_ib.from_le();
    insn_t *start_inst = new insn_t((insn_bits_t)ib);
    printf("PC: 0x%x\n", start_pc);
    printf("opcode: 0x%x\n", start_inst->bits());
    print_cpu_state(cpu->get_state());
    reg_t r = fast_rv32i_addi(cpu, *start_inst, start_pc);
    print_cpu_state(cpu->get_state());
}