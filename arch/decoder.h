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
    disassembler_t *disasm;
    Decoder(uint8_t dw, disassembler_t *d)
    {
        decode_width = dw;
        disasm = d;
    }
    std::vector<reg_t> src_regs(InstPtr ins, std::string ins_name);

private:
    std::queue<InstPtr> decode_queue;
};