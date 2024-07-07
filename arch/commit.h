#pragma once

#include "../processor.h"
#include "scoreboard.h"

class Commit
{
public:
    uint8_t num_commit;
    Commit(Scoreboard *s, uint8_t nc)
    {
        sb = s;
        num_commit = nc;
    }
    void commit_insts();

private:
    Scoreboard *sb;
};