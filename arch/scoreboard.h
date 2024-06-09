#pragma once

#include "../processor.h"
#include "decoder.h"

class Scoreboard
{
public:
    uint8_t scoreboard_size;
    Scoreboard(uint8_t ss)
    {
        scoreboard_size = ss;
    };
    void load_into_scoreboard(InstPtr ins);
    void get_insts_from_decode(Decoder *d);
    bool is_scoreboard_full();
    bool is_scoreboard_empty();
    InstPtr release_inst();
    void issue(InstPtr ins);

private:
    std::vector<InstPtr> scoreboard;
};