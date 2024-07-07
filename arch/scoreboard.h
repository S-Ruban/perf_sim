#pragma once

#include "../processor.h"
#include "decoder.h"

class Scoreboard
{
public:
    uint8_t scoreboard_size;
    uint8_t num_issue;
    Scoreboard(uint8_t ss, uint8_t ni)
    {
        scoreboard_size = ss;
        num_issue = ni;
        for (int r = 0; r < 32; r++)
            operandForwarded[r] = true;
    };
    void load_into_scoreboard(InstPtr ins);
    void get_insts_from_decode(Decoder *d);
    bool is_scoreboard_full();
    bool is_scoreboard_empty();
    bool is_execute_queue_empty();
    void add_to_execute(InstPtr ins);
    InstPtr get_from_execute();
    InstPtr release_inst();
    InstPtr head();
    void issue();
    void display();
    void register_ready(reg_t r);

private:
    std::vector<InstPtr> scoreboard;
    std::vector<InstPtr> execute_queue;
    bool operandForwarded[32];
};