#include "../processor.h"

struct instruction
{
    insn_t *inst;
    reg_t pc;
    uint32_t inst_cnt;
};

static uint32_t ic_cntr = 0;

void fetch(processor_t *cpu, memif_t *memory, reg_t *pc);