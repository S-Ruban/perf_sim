#pragma once
#include "../processor.h"

enum EXECUTION_UNIT
{
    NILL,
    ALU,
    BJU,
    MOU
};

class Instruction
{
public:
    insn_t *inst;
    reg_t pc;
    uint32_t inst_cnt;
    EXECUTION_UNIT exe_unit;
    Instruction()
    {
        inst = nullptr;
        pc = 0x0;
        inst_cnt = 0xffffffff;
    }
    Instruction(reg_t p, reg_t opcode, uint32_t ic)
    {
        inst = new insn_t((insn_bits_t)opcode);
        pc = p;
        inst_cnt = ic;
        exe_unit = NILL;
    }
};

typedef Instruction *InstPtr;