#pragma once
#include "../processor.h"
#include <unordered_map>
#include <queue>

enum EXECUTION_UNIT
{
    NILL,
    ALU, // ALU insts
    BJU, // branch/jump insts
    MOU  // load/store insts
};

enum STATUS
{
    NOT_ISSUED,
    GOING_TO_ISSUE,
    ISSUED
};

struct dep_reg
{
    reg_t reg;
    bool is_data_available;
};

class Instruction
{
public:
    insn_t *inst;
    reg_t pc;
    uint32_t inst_cnt;
    EXECUTION_UNIT exe_unit;
    std::vector<dep_reg> r;
    STATUS status;

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
        {"beqz", BJU},
        {"bge", BJU},
        {"bgeu", BJU},
        {"bgez", BJU},
        {"blt", BJU},
        {"bltu", BJU},
        {"bltz", BJU},
        {"bne", BJU},
        {"bnez", BJU},
        {"c.add", ALU},
        {"c.addi", ALU},
        {"c.addi16sp", ALU},
        {"c.addi4spn", ALU},
        {"c.addiw", ALU},
        {"c.addw", ALU},
        {"c.and", ALU},
        {"c.andi", ALU},
        {"c.beqz", BJU},
        {"c.bnez", BJU},
        {"c.j", BJU},
        {"c.jalr", BJU},
        {"c.jr", BJU},
        {"c.lbu", BJU},
        {"c.ld", BJU},
        {"c.ldsp", BJU},
        {"c.lh", BJU},
        {"c.lhu", BJU},
        {"c.li", ALU},
        {"c.lui", ALU},
        {"c.lw", BJU},
        {"c.lwsp", BJU},
        {"c.mul", ALU},
        {"c.mv", ALU},
        {"c.nop", ALU},
        {"c.not", ALU},
        {"c.or", ALU},
        {"c.sb", BJU},
        {"c.sd", BJU},
        {"c.sdsp", ALU},
        {"c.sext.b", ALU},
        {"c.sext.h", ALU},
        {"c.sh", BJU},
        {"c.slli", ALU},
        {"c.srai", ALU},
        {"c.srli", ALU},
        {"c.sub", ALU},
        {"c.subw", ALU},
        {"c.sw", BJU},
        {"c.swsp", BJU},
        {"c.unimp", ALU},
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
        {"j", BJU},
        {"jal", BJU},
        {"jalr", BJU},
        {"jr", BJU},
        {"lb", MOU},
        {"lbu", MOU},
        {"ld", MOU},
        {"lh", MOU},
        {"lhu", MOU},
        {"li", ALU},
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
        {"mv", ALU},
        {"nop", ALU},
        {"not", ALU},
        {"or", ALU},
        {"orc.b", ALU},
        {"ori", ALU},
        {"orn", ALU},
        {"pack", ALU},
        {"packh", ALU},
        {"packw", ALU},
        {"rem", ALU},
        {"remu", ALU},
        {"remuw", ALU},
        {"remw", ALU},
        {"ret", ALU},
        {"rev8", ALU},
        {"rol", ALU},
        {"rolw", ALU},
        {"ror", ALU},
        {"rori", ALU},
        {"roriw", ALU},
        {"rorw", ALU},
        {"sb", BJU},
        {"sd", BJU},
        {"seqz", ALU},
        {"sext.b", ALU},
        {"sext.h", ALU},
        {"sext.w", ALU},
        {"sh", ALU},
        {"sh1add", ALU},
        {"sh1add.uw", ALU},
        {"sh2add", ALU},
        {"sh2add.uw", ALU},
        {"sh3add", ALU},
        {"sh3add.uw", ALU},
        {"sll", ALU},
        {"slli", ALU},
        {"slli.uw", ALU},
        {"slliw", ALU},
        {"sllw", ALU},
        {"slt", ALU},
        {"slti", ALU},
        {"sltiu", ALU},
        {"sltu", ALU},
        {"snez", ALU},
        {"sra", ALU},
        {"srai", ALU},
        {"sraiw", ALU},
        {"sraw", ALU},
        {"sret", ALU},
        {"srl", ALU},
        {"srli", ALU},
        {"srliw", ALU},
        {"srlw", ALU},
        {"sub", ALU},
        {"subw", ALU},
        {"sw", BJU},
        {"unimp", ALU},
        {"xnor", ALU},
        {"xor", ALU},
        {"xori", ALU},
        {"zext.h", ALU},
        {"zext.w", ALU},
    };
};

typedef Instruction *InstPtr;
