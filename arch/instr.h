#pragma once
#include "../processor.h"
#include <unordered_map>
#include <queue>

enum EXECUTION_UNIT
{
    NILL,
    ALU, // ALUinsts
    BJU, // branch/jumpinsts
    MOU  // load/storeinsts
};

enum STATUS
{
    NOT_ISSUED,
    ISSUED,
    COMPLETED
};

class Instruction
{
public:
    insn_t *inst;
    reg_t pc;
    uint32_t inst_cnt;
    EXECUTION_UNIT exe_unit;
    std::vector<reg_t> dep_regs;
    STATUS status;
    std::string inst_name;

    Instruction()
    {
        inst = nullptr;
        pc = 0x0;
        inst_cnt = 0xffffffff;
    }
    Instruction(reg_t p, reg_t opcode, uint32_t ic)
    {
        inst = new insn_t((insn_bits_t)opcode);
        pc = p;
        inst_cnt = ic;
        exe_unit = NILL;
        status = NOT_ISSUED;
    }
    std::unordered_map<std::string, EXECUTION_UNIT> inst2exu = {
        {"add", ALU},
        {"add.uw", ALU},
        {"addi", ALU},
        {"addiw", ALU},
        {"addw", ALU},
        {"and", ALU},
        {"andi", ALU},
        {"andn", ALU},
        {"auipc", ALU},
        {"beq", BJU},
        {"bge", BJU},
        {"bgeu", BJU},
        {"blt", BJU},
        {"bltu", BJU},
        {"bne", BJU},
        {"c.add", ALU},
        {"c.addi", ALU},
        {"c.addi4spn", ALU},
        {"c.addw", ALU},
        {"c.and", ALU},
        {"c.andi", ALU},
        {"c.beqz", BJU},
        {"c.bnez", BJU},
        {"c.j", BJU},
        {"c.jalr", BJU},
        {"c.jr", BJU},
        {"c.lbu", MOU},
        {"c.lh", MOU},
        {"c.lhu", MOU},
        {"c.li", ALU},
        {"c.lui", ALU},
        {"c.lw", MOU},
        {"c.lwsp", MOU},
        {"c.mul", ALU},
        {"c.mv", ALU},
        {"c.not", ALU},
        {"c.or", ALU},
        {"c.sb", MOU},
        {"c.sext.b", ALU},
        {"c.sext.h", ALU},
        {"c.sh", MOU},
        {"c.slli", ALU},
        {"c.srai", ALU},
        {"c.srli", ALU},
        {"c.sub", ALU},
        {"c.subw", ALU},
        {"c.sw", MOU},
        {"c.swsp", MOU},
        {"c.xor", ALU},
        {"c.zext.b", ALU},
        {"c.zext.h", ALU},
        {"c.zext.w", ALU},
        {"clz", ALU},
        {"clzw", ALU},
        {"cpop", ALU},
        {"cpopw", ALU},
        {"csrc", ALU},
        {"csrci", ALU},
        {"csrr", ALU},
        {"csrrc", ALU},
        {"csrrci", ALU},
        {"csrrs", ALU},
        {"csrrsi", ALU},
        {"csrrw", ALU},
        {"csrrwi", ALU},
        {"csrs", ALU},
        {"csrsi", ALU},
        {"csrw", ALU},
        {"csrwi", ALU},
        {"ctz", ALU},
        {"ctzw", ALU},
        {"czero.eqz", ALU},
        {"czero.nez", ALU},
        {"div", ALU},
        {"divu", ALU},
        {"divuw", ALU},
        {"divw", ALU},
        {"jal", BJU},
        {"jalr", BJU},
        {"lb", MOU},
        {"lbu", MOU},
        {"ld", MOU},
        {"lh", MOU},
        {"lhu", MOU},
        {"lui", ALU},
        {"lw", MOU},
        {"lwu", MOU},
        {"max", ALU},
        {"maxu", ALU},
        {"min", ALU},
        {"minu", ALU},
        {"mul", ALU},
        {"mulh", ALU},
        {"mulhsu", ALU},
        {"mulhu", ALU},
        {"mulw", ALU},
        {"or", ALU},
        {"ori", ALU},
        {"orn", ALU},
        {"pack", ALU},
        {"packh", ALU},
        {"packw", ALU},
        {"rem", ALU},
        {"remu", ALU},
        {"remuw", ALU},
        {"remw", ALU},
        {"rol", ALU},
        {"rolw", ALU},
        {"ror", ALU},
        {"rori", ALU},
        {"roriw", ALU},
        {"rorw", ALU},
        {"sb", BJU},
        {"sd", BJU},
        {"sext.b", ALU},
        {"sext.h", ALU},
        {"sh", ALU},
        {"sh1add", ALU},
        {"sh2add", ALU},
        {"sh3add", ALU},
        {"sll", ALU},
        {"slli", ALU},
        {"slli.uw", ALU},
        {"slliw", ALU},
        {"sllw", ALU},
        {"slt", ALU},
        {"slti", ALU},
        {"sltiu", ALU},
        {"sltu", ALU},
        {"sra", ALU},
        {"srai", ALU},
        {"sraiw", ALU},
        {"sraw", ALU},
        {"srl", ALU},
        {"srli", ALU},
        {"srliw", ALU},
        {"srlw", ALU},
        {"sub", ALU},
        {"subw", ALU},
        {"sw", BJU},
        {"xnor", ALU},
        {"xor", ALU},
        {"xori", ALU},
    };
};

typedef Instruction *InstPtr;
