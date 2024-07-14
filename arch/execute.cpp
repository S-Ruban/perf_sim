#include "execute.h"

void ALU::execute(InstPtr ins, processor_t *proc, reg_t pc, Scoreboard *s, std::function<reg_t(processor_t *p, insn_t insn, reg_t pc)> execute_inst)
{
    execute_inst(proc, *(ins->inst), pc);
    s->register_ready(ins->inst->rd());
    ins->status = COMPLETED;
}

void Execute::get_inst_from_scoreboard(Scoreboard *s)
{
    while (!s->is_execute_queue_empty())
    {
        InstPtr ins = s->get_from_execute();
        reg_t pc = ins->pc;
        std::string ins_name = ins->inst_name;
        switch (ins->exe_unit)
        {
        case 1:
            if (function_map.find(ins_name) != function_map.end())
                ALU::execute(ins, proc, pc, s, function_map[ins_name]);
            break;
        }
    }
}