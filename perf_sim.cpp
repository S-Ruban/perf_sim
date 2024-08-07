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

#include "arch/fetch.h"
#include "arch/decoder.h"
#include "arch/scoreboard.h"
#include "arch/execute.h"
#include "arch/commit.h"

using namespace std;
class simif_t;

#define MAX_CYCLE 100

void print_cpu_state(state_t *state)
{
    for (int r = 0; r < 32; r++)
        printf("x%d: 0x%016x\n", r, state->XPR[r]);
    for (int f = 0; f < 32; f++)
        printf("f%d: 0x%016x\n", f, state->FPR[f]);
    // auto cycle_count = state->mcycle;
    // uint64_t pc = state->pc;
    // printf("pc: 0x%016x\n", pc);
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

int main(int argc, char **argv)
{
    uint32_t cycle = 0;

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
    reg_t pc;

    disassembler_t *dis = new disassembler_t(isa);

    Fetch fetch_block = Fetch(cpu, &memif, 4, 4);
    Decoder decoder = Decoder(4, dis);
    Scoreboard scoreboard = Scoreboard(16, 2);
    Execute execute = Execute(isa, cpu, dis);
    Commit commit = Commit(&scoreboard, 2);

    map<string, uint64_t> elf = load_elf("dep_mul.elf", &memif, &pc, 64);

    // print_cpu_state(cpu->get_state());

    while (cycle < MAX_CYCLE)
    {
        printf("\n\nCycle %d\n", cycle);
        commit.commit_insts();
        execute.get_inst_from_scoreboard(&scoreboard);
        scoreboard.display();
        scoreboard.get_insts_from_decode(&decoder);
        decoder.decode(&fetch_block);
        fetch_block.fetch(&pc);
        cycle++;
    }

    // for (string s : dis->rv_insts)
    //     cout << s << "\n";

    print_cpu_state(cpu->get_state());
}