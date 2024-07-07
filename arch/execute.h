#pragma once

#include "../processor.h"
#include "scoreboard.h"
#include "../disasm.h"
#include "../insn_list.h"

class ALU
{
public:
    ALU(){};
    void execute(InstPtr ins, processor_t *proc, reg_t tpc, Scoreboard *s);
};

class Execute : ALU
{
public:
    const isa_parser_t *isa;
    processor_t *proc;
    disassembler_t *disasm;
    ALU *alu;
    Execute(const isa_parser_t *dis, processor_t *cpu, disassembler_t *d)
    {
        alu = new ALU();
        isa = dis;
        proc = cpu;
        disasm = d;
    }
    void get_inst_from_scoreboard(Scoreboard *s);
};