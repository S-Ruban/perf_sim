#include "../processor.h"

struct fetch_bundle
{
    reg_t pc[4];
    reg_t opcode[4];
    uint32_t ic[4];
};

static uint32_t ic_cntr = 0;

void fetch(processor_t *cpu, memif_t *memory, reg_t *pc);