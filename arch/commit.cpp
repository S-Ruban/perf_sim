#include "commit.h"

void Commit::commit_insts()
{
    int i = 0;
    while (i < num_commit)
    {
        InstPtr oldest_inst = sb->head();
        if (oldest_inst != NULL && oldest_inst->status == COMPLETED)
        {
            printf("COMMIT:\t\t\tPC: 0x%08x\topcode: 0x%08x\ticount=%d\texe_unit: %d\n", oldest_inst->pc, oldest_inst->inst->bits(), oldest_inst->inst_cnt, oldest_inst->exe_unit);
            sb->release_inst();
            i++;
        }
        else
            break;
    }
}