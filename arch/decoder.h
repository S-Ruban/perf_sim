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
    uint8_t decode_width;
    InstPtr release_inst();
    const isa_parser_t *isa;
    processor_t *proc ;
    Decoder(uint8_t dw, const isa_parser_t *dis, processor_t* cpu)
    {
        decode_width = dw;
        isa = dis;
        proc = cpu ;
    }

private:
    std::queue<InstPtr> decode_queue;
};