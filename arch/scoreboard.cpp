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
    if (!is_scoreboard_empty())
        release_inst();
    printf("\n");
}

InstPtr Scoreboard::release_inst()
{
    InstPtr inst = scoreboard.front();
    scoreboard.erase(scoreboard.begin());
    return inst;
}

void Scoreboard::issue(InstPtr ins)
{
    if (ins->status == NOT_ISSUED)
    {
        ins->status == GOING_TO_ISSUE;
    }
}

bool Scoreboard::is_scoreboard_empty()
{
    return scoreboard.empty();
}