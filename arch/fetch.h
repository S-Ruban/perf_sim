#pragma once

#include "../processor.h"
#include <queue>

static uint32_t ic_cntr;

class Instruction
{
public:
    insn_t *inst;
    reg_t pc;
    uint32_t inst_cnt;
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
    }
};

typedef Instruction *InstPtr;

class Fetch
{
public:
    processor_t *cpu;
    memif_t *memory_interface;
    uint8_t fetch_width;
    uint8_t fetch_queue_size;
    Fetch() {}
    Fetch(processor_t *p, memif_t *m, uint8_t fw, uint8_t fqs)
    {
        cpu = p;
        memory_interface = m;
        fetch_width = fw;
        fetch_queue_size = fqs;
    }
    void fetch(reg_t *pc);
    InstPtr release_inst();
    bool is_fetch_queue_empty();

private:
    std::queue<InstPtr> fetch_queue;
};