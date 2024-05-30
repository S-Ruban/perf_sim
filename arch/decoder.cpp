#include "decoder.h"
#include "../insn_list.h"

bool Decoder::is_decode_queue_full()
{
    return decode_queue.size() == decode_width;
}

void Decoder::load_into_decode_queue(InstPtr ins)
{
    // if (ins->inst->bits() & MATCH_ADDI == MATCH_ADDI)
    //     printf("addi\t");
    decode_queue.push(ins);
    printf("DECODE:\t\t\tPC: 0x%08x\topcode: 0x%08x\ticount=%d\n", ins->pc, ins->inst->bits(), ins->inst_cnt);
    disassembler_t *dis = new disassembler_t(isa);
    std::string ins_name = dis->lookup(*ins->inst)->get_name();
    reg_t tpc = ins->pc;
    std::cout << ins_name << "\n";
    // if (ins_name == "addi")
    //     fast_rv64e_addi(proc, ins->inst, tpc);
}

void Decoder::decode(Fetch *f)
{
    while (!f->is_fetch_queue_empty() && !is_decode_queue_full())
    {
        InstPtr ins = f->release_inst();
        load_into_decode_queue(ins);
    }
    release_inst();
    printf("\n");
}

InstPtr Decoder::release_inst()
{
    InstPtr inst = decode_queue.front();
    decode_queue.pop();
    return inst;
}
