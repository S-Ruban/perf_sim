#pragma once

#include "../processor.h"
#include "fetch.h"
#include "../disasm.h"

class Decoder
{
public:
    void decode(Fetch *f);
    void load_into_decode_queue(InstPtr ins);
    bool is_decode_queue_full();
    bool is_decode_queue_empty();
    uint8_t decode_width;
    InstPtr release_inst();
    const isa_parser_t *isa;
    processor_t *proc;
    disassembler_t *disasm;
    Decoder(uint8_t dw, const isa_parser_t *dis, processor_t *cpu, disassembler_t *d)
    {
        decode_width = dw;
        isa = dis;
        proc = cpu;
        disasm = d;
    }

private:
    std::queue<InstPtr> decode_queue;
};