#include "execute.h"

void ALU::execute(InstPtr ins, processor_t *proc, reg_t pc, Scoreboard *s)
{
    if (ins->inst_name == "add")
        fast_rv64i_add(proc, *(ins->inst), pc);
    if (ins->inst_name == "ori")
        fast_rv64i_ori(proc, *(ins->inst), pc);
    // printf("Executed PC %x", tpc);
    // std::cout << "\tins name:" << ins->inst_name << std::endl;
    s->register_ready(ins->inst->rd());
    ins->status = COMPLETED;
}

void Execute::get_inst_from_scoreboard(Scoreboard *s)
{
    while (!s->is_execute_queue_empty())
    {
        InstPtr ins = s->get_from_execute();
        reg_t pc = ins->pc;
        switch (ins->exe_unit)
        {
        case 1:
            ALU::execute(ins, proc, pc, s);
            break;
        }
    }
}