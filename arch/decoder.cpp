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
    ins->inst_name = disasm->lookup(*ins->inst)->get_name();
    std::string ins_name = ins->inst_name;
    ins->exe_unit = ins->inst2exu[ins_name];
    printf("DECODE:\t\t\tPC: 0x%08x\topcode: 0x%08x\ticount=%d\texe_unit: %d\t", ins->pc, ins->inst->bits(), ins->inst_cnt, ins->exe_unit);
    std::cout << ins_name << std::endl;
    std::vector<reg_t> src_reg;
    {
        if (ins_name == "addi")
            ins->dep_regs.push_back(ins->inst->rs1());
        if (ins_name == "add")
        {
            ins->dep_regs.push_back(ins->inst->rs1());
            ins->dep_regs.push_back(ins->inst->rs2());
        }
    }
    // std::cout << ins_name << "\n";
    // if (ins_name == "addi")
    //     fast_rv64e_addi(proc, *(ins->inst), tpc);
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

std::vector<reg_t> src_regs(InstPtr ins, std::string ins_name)
{
    if (ins_name == "add")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "add.uw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "addi")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "addiw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "addw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "and")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "andi")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "andn")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "auipc")
        return (std::vector<reg_t>());
    if (ins_name == "beq")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "bge")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "bgeu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "blt")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "bltu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "bne")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "c.add")
        return (std::vector<reg_t>(ins->inst->rvc_rs1(), ins->inst->rvc_rs2()));
    if (ins_name == "c.addi")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.addi4spn")
        return (std::vector<reg_t>(X_SP));
    if (ins_name == "c.addw")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.and")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.andi")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.beqz")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.bnez")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.j")
        return (std::vector<reg_t>());
    if (ins_name == "c.jal")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.jalr")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.jr")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.lbu")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.lh")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.lhu")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.li")
        return (std::vector<reg_t>());
    if (ins_name == "c.lui")
        return (std::vector<reg_t>());
    if (ins_name == "c.lw")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.lwsp")
        return (std::vector<reg_t>(X_SP));
    if (ins_name == "c.mul")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.mv")
        return (std::vector<reg_t>(ins->inst->rvc_rs2()));
    if (ins_name == "c.not")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.or")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.sb")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.sext.b")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.sext.h")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.sh")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.slli")
        return (std::vector<reg_t>(ins->inst->rvc_rs1()));
    if (ins_name == "c.srai")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.srli")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.sub")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.subw")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.sw")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.swsp")
        return (std::vector<reg_t>(X_SP, ins->inst->rvc_rs2()));
    if (ins_name == "c.xor")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()));
    if (ins_name == "c.zext.b")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.zext.h")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "c.zext.w")
        return (std::vector<reg_t>(ins->inst->rvc_rs1s()));
    if (ins_name == "clz")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "clzw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "cpop")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "cpopw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "csrc")
        return (std::vector<reg_t>());
    if (ins_name == "csrci")
        return (std::vector<reg_t>());
    if (ins_name == "csrr")
        return (std::vector<reg_t>());
    if (ins_name == "csrrc")
        return (std::vector<reg_t>());
    if (ins_name == "csrrci")
        return (std::vector<reg_t>());
    if (ins_name == "csrrs")
        return (std::vector<reg_t>());
    if (ins_name == "csrrsi")
        return (std::vector<reg_t>());
    if (ins_name == "csrrw")
        return (std::vector<reg_t>());
    if (ins_name == "csrrwi")
        return (std::vector<reg_t>());
    if (ins_name == "csrs")
        return (std::vector<reg_t>());
    if (ins_name == "csrsi")
        return (std::vector<reg_t>());
    if (ins_name == "csrw")
        return (std::vector<reg_t>());
    if (ins_name == "csrwi")
        return (std::vector<reg_t>());
    if (ins_name == "ctz")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "ctzw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "czero.eqz")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "czero.nez")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "div")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "divu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "divuw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "divw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "jal")
        return (std::vector<reg_t>());
    if (ins_name == "jalr")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "lb")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "lbu")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "ld")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "lh")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "lhu")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "lui")
        return (std::vector<reg_t>());
    if (ins_name == "lw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "lwu")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "max")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "maxu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "min")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "minu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "mul")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "mulh")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "mulhsu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "mulhu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "mulw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "or")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "ori")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "orn")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "pack")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "packh")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "packw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "rem")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "remu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "remuw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "remw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "rol")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "rolw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "ror")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "rori")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "roriw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "rorw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sb")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sd")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sext.b")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sext.h")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sh")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sh1add")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sh2add")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sh3add")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sll")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "slli")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "slli.uw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "slliw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "sllw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "slt")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "slti")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "sltiu")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "sltu")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sra")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "srai")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "sraiw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "sraw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "srl")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "srli")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "srliw")
        return (std::vector<reg_t>(ins->inst->rs1()));
    if (ins_name == "srlw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sub")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "subw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "sw")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "xnor")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "xor")
        return (std::vector<reg_t>(ins->inst->rs1(), ins->inst->rs2()));
    if (ins_name == "xori")
        return (std::vector<reg_t>(ins->inst->rs1()));
};
