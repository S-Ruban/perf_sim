#pragma once

#include "../processor.h"
#include "instr.h"

static uint32_t ic_cntr;

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