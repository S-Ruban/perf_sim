#pragma once

#include "../processor.h"
#include "scoreboard.h"
#include "../disasm.h"
#include "../insn_list.h"
// #include <functional>

class ALU
{
public:
    ALU(){};
    void execute(InstPtr ins, processor_t *proc, reg_t tpc, Scoreboard *s, std::function<reg_t(processor_t *p, insn_t insn, reg_t pc)> execute_inst);
};

class Execute : ALU
{
public:
    const isa_parser_t *isa;
    processor_t *proc;
    disassembler_t *disasm;
    ALU *alu;
    std::unordered_map<std::string, std::function<reg_t(processor_t *p, insn_t insn, reg_t pc)>> function_map;
    Execute(const isa_parser_t *dis, processor_t *cpu, disassembler_t *d)
    {
        alu = new ALU();
        isa = dis;
        proc = cpu;
        disasm = d;
        function_map = {
            {"add", fast_rv64i_add},
            {"addi", fast_rv64i_addi},
            {"andi", fast_rv64i_andi},
            {"ori", fast_rv64i_ori},
            {"xori", fast_rv64i_xori},
            {"div", fast_rv64i_div},
            {"divu", fast_rv64i_divu},
            {"divuw", fast_rv64i_divuw},
            {"divw", fast_rv64i_divw},
            {"mul", fast_rv64i_mul},
            {"mulh", fast_rv64i_mulh},
            {"mulhsu", fast_rv64i_mulhsu},
            {"mulhu", fast_rv64i_mulhu},
            {"mulw", fast_rv64i_mulw},
            {"sra", fast_rv64i_sra},
            {"srai", fast_rv64i_srai},
            {"sraiw", fast_rv64i_sraiw},
            {"sraw", fast_rv64i_sraw},
            {"srl", fast_rv64i_srl},
            {"srli", fast_rv64i_srli},
            {"srliw", fast_rv64i_srliw},
            {"srlw", fast_rv64i_srlw},
            {"sub", fast_rv64i_sub},
            {"subw", fast_rv64i_subw},
        };
    }
    void get_inst_from_scoreboard(Scoreboard *s);
};