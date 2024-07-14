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
    ins->dep_regs = src_regs(ins);
    // if (ins->inst_name == "add")
    //     ins->dep_regs = std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()};
    // if (ins->inst_name == "ori")
    //     ins->dep_regs = std::vector<reg_t>{ins->inst->rs1()};
    for (int i = 0; i < ins->dep_regs.size(); i++)
        printf("%d x%d\n", i, ins->dep_regs[i]);
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

std::vector<reg_t> Decoder::src_regs(InstPtr ins)
{
    if (ins->inst_name == "add")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "add.uw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "addi")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "addiw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "addw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "and")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "andi")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "andn")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "auipc")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "beq")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "bge")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "bgeu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "blt")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "bltu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "bne")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "c.add")
        return (std::vector<reg_t>(ins->inst->rvc_rs1(), ins->inst->rvc_rs2()));
    if (ins->inst_name == "c.addi")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.addi4spn")
        return (std::vector<reg_t>{X_SP});
    if (ins->inst_name == "c.addw")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.and")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.andi")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.beqz")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.bnez")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.j")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "c.jal")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.jalr")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.jr")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.lbu")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.lh")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.lhu")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.li")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "c.lui")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "c.lw")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.lwsp")
        return (std::vector<reg_t>{X_SP});
    if (ins->inst_name == "c.mul")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.mv")
        return (std::vector<reg_t>(ins->inst->rvc_rs2()));
    if (ins->inst_name == "c.not")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.or")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.sb")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.sext.b")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.sext.h")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.sh")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.slli")
        return (std::vector<reg_t>{ins->inst->rvc_rs1()});
    if (ins->inst_name == "c.srai")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.srli")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.sub")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.subw")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.sw")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.swsp")
        return (std::vector<reg_t>{X_SP, ins->inst->rvc_rs2()});
    if (ins->inst_name == "c.xor")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s(), ins->inst->rvc_rs2s()});
    if (ins->inst_name == "c.zext.b")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.zext.h")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "c.zext.w")
        return (std::vector<reg_t>{ins->inst->rvc_rs1s()});
    if (ins->inst_name == "clz")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "clzw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "cpop")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "cpopw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "csrc")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrci")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrr")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrrc")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrrci")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrrs")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrrsi")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrrw")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrrwi")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrs")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrsi")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrw")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "csrwi")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "ctz")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "ctzw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "czero.eqz")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "czero.nez")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "div")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "divu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "divuw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "divw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "jal")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "jalr")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "lb")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "lbu")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "ld")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "lh")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "lhu")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "lui")
        return (std::vector<reg_t>{});
    if (ins->inst_name == "lw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "lwu")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "max")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "maxu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "min")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "minu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "mul")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "mulh")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "mulhsu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "mulhu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "mulw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "or")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "ori")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "orn")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "pack")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "packh")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "packw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "rem")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "remu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "remuw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "remw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "rol")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "rolw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "ror")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "rori")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "roriw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "rorw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sb")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sd")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sext.b")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sext.h")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sh")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sh1add")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sh2add")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sh3add")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sll")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "slli")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "slli.uw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "slliw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "sllw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "slt")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "slti")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "sltiu")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "sltu")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sra")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "srai")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "sraiw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "sraw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "srl")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "srli")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "srliw")
        return (std::vector<reg_t>{ins->inst->rs1()});
    if (ins->inst_name == "srlw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sub")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "subw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "sw")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "xnor")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "xor")
        return (std::vector<reg_t>{ins->inst->rs1(), ins->inst->rs2()});
    if (ins->inst_name == "xori")
        return (std::vector<reg_t>{ins->inst->rs1()});
    return (std::vector<reg_t>{});
};
