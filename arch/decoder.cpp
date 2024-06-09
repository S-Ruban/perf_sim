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
    std::string ins_name = disasm->lookup(*ins->inst)->get_name();
    reg_t tpc = ins->pc;
    ins->exe_unit = ins->inst2exu[ins_name];
    printf("DECODE:\t\t\tPC: 0x%08x\topcode: 0x%08x\ticount=%d\texe_unit: %d\t", ins->pc, ins->inst->bits(), ins->inst_cnt, ins->exe_unit);
    if (ins->inst->rs1())
        printf("rs1: x%d\t", ins->inst->rs1());
    else if (ins->inst->rvc_rs1())
        printf("rs1: x%d\t", ins->inst->rvc_rs1());
    else if (ins->inst->rvc_rs1s())
        printf("rs1: x%d\t", ins->inst->rvc_rs1s());
    if (ins->inst->rs2())
        printf("rs2: x%d\t", ins->inst->rs2());
    else if (ins->inst->rvc_rs2())
        printf("rs2: x%d\t", ins->inst->rvc_rs2());
    else if (ins->inst->rvc_rs2s())
        printf("rs2: x%d\t", ins->inst->rvc_rs2s());
    if (ins->inst->rs3())
        printf("rs3: x%d\t", ins->inst->rs3());
    printf("\n");
    // std::cout << ins_name << "\n";
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
    // release_inst();
    // printf("\n");
}

InstPtr Decoder::release_inst()
{
    InstPtr inst = decode_queue.front();
    decode_queue.pop();
    return inst;
}

bool Decoder::is_decode_queue_empty()
{
    return decode_queue.empty();
}
