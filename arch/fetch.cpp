#include "fetch.h"

void Fetch::fetch(reg_t *pc)
{
    reg_t fetch_bundle_pc = *pc;
    target_endian<uint16_t> fetch_data[4];
    for (int i = 0; i < sizeof(fetch_data) / sizeof(target_endian<uint16_t>); i++)
        fetch_data[i] = memory_interface->read_uint16(*pc + (i << 1));
    InstPtr *fetch_bundle = new InstPtr[fetch_width];
    int fb_dat = 0, fb_idx = 0;
    for (int fb_idx = 0; fb_idx < 4; fb_idx++)
    {
        if ((fb_dat > fetch_width - 1) || fetch_queue.size() == fetch_queue_size)
            break;
        if ((fetch_data[fb_dat].from_le() & (uint16_t)0x3) == 0x3)
        {
            if (fb_dat == 3)
                break;
            fetch_bundle[fb_idx] = new Instruction(*pc, (reg_t)((fetch_data[fb_dat + 1].from_le() << 16) | fetch_data[fb_dat].from_le()), ic_cntr);
            fb_dat++;
        }
        else
            fetch_bundle[fb_idx] = new Instruction(*pc, (reg_t)((fetch_data[fb_dat].from_le())), ic_cntr);
        fetch_queue.push(fetch_bundle[fb_idx]);
        printf("FETCH:\t\t\tPC: 0x%08x\topcode: 0x%08x\ticount=%d\n", fetch_bundle[fb_idx]->pc, fetch_bundle[fb_idx]->inst->bits(), fetch_bundle[fb_idx]->inst_cnt);
        *pc += fetch_bundle[fb_idx]->inst->length();
        ic_cntr++;
        fb_dat++;
    }
}

InstPtr Fetch::release_inst()
{
    InstPtr inst = fetch_queue.front();
    fetch_queue.pop();
    return inst;
}

bool Fetch::is_fetch_queue_empty()
{
    return fetch_queue.empty();
}