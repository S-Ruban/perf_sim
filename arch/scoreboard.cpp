#include "scoreboard.h"
#include "../insn_list.h"

bool Scoreboard::is_scoreboard_full()
{
    return scoreboard.size() == scoreboard_size;
}

void Scoreboard::load_into_scoreboard(InstPtr ins)
{
    scoreboard.push_back(ins);
    printf("SCOREBOARD:\t\t\tPC: 0x%08x\topcode: 0x%08x\ticount=%d\texe_unit: %d\n", ins->pc, ins->inst->bits(), ins->inst_cnt, ins->exe_unit);
}

void Scoreboard::get_insts_from_decode(Decoder *d)
{
    while (!d->is_decode_queue_empty() && !is_scoreboard_full())
    {
        InstPtr ins = d->release_inst();
        load_into_scoreboard(ins);
    }
    issue();
    printf("\n");
}

InstPtr Scoreboard::release_inst()
{
    InstPtr inst = scoreboard.front();
    scoreboard.erase(scoreboard.begin());
    return inst;
}

void Scoreboard::issue()
{
    int i = 0;
    for (InstPtr ins : scoreboard)
    {
        if (i >= num_issue)
            return;
        if (ins->status != NOT_ISSUED)
            break;
        // printf("Err: 0x%x\t", ins->pc);
        for (reg_t r : ins->dep_regs)
        {
            // printf("x%d ", r);
            if (!operandForwarded[r])
                return;
        }
        // printf("\n");
        ins->status = ISSUED;
        operandForwarded[ins->inst->rd()] = false;
        add_to_execute(ins);
        i++;
    }
}

bool Scoreboard::is_scoreboard_empty()
{
    return scoreboard.empty();
}

bool Scoreboard::is_execute_queue_empty()
{
    return execute_queue.empty();
}

void Scoreboard::display()
{
    for (InstPtr ins : scoreboard)
        printf("SB:\t\t\tPC: 0x%08x\topcode: 0x%08x\ticount=%d\texe_unit: %d\n", ins->pc, ins->inst->bits(), ins->inst_cnt, ins->exe_unit);
    for (InstPtr ins : execute_queue)
        printf("EQ:\t\t\tPC: 0x%08x\topcode: 0x%08x\ticount=%d\texe_unit: %d\n", ins->pc, ins->inst->bits(), ins->inst_cnt, ins->exe_unit);
}

void Scoreboard::add_to_execute(InstPtr ins)
{
    execute_queue.push_back(ins);
}

InstPtr Scoreboard::get_from_execute()
{
    if (!is_execute_queue_empty())
    {
        InstPtr inst = execute_queue.front();
        execute_queue.erase(execute_queue.begin());
        return inst;
    }
}

void Scoreboard::register_ready(reg_t r)
{
    operandForwarded[r] = true;
}

InstPtr Scoreboard::head()
{
    if (is_scoreboard_empty())
        return NULL;
    return scoreboard.front();
}