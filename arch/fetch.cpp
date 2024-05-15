#include "fetch.h"

// insn_t *start_inst = new insn_t((insn_bits_t)ib);

void fetch(processor_t *cpu, memif_t *memory, reg_t *pc)
{
    reg_t fetch_bundle_pc = *pc;
    target_endian<uint16_t> fetch_data[4];
    for (int i = 0; i < sizeof(fetch_data) / sizeof(target_endian<uint16_t>); i++)
        fetch_data[i] = memory->read_uint16(*pc + (i << 1));
    struct instruction fetch_bundle[4];
    for (int i = 0; i < 4; i++)
        fetch_bundle[i] = {nullptr, 0x0, 0xffffffff};
    int fb_dat = 0, fb_idx = 0;
    for (int fb_idx = 0; fb_idx < 4; fb_idx++)
    {
        if (fb_dat > sizeof(fetch_bundle) / sizeof(fetch_bundle[0]) - 1)
            break;
        fetch_bundle[fb_idx].pc = *pc;
        fetch_bundle[fb_idx].inst_cnt = ic_cntr;
        ic_cntr++;
        if ((fetch_data[fb_dat].from_le() & (uint16_t)0x3) == 0x3)
        {
            if (fb_dat == 3)
                break;
            fetch_bundle[fb_idx].inst = new insn_t((insn_bits_t)((fetch_data[fb_dat + 1].from_le() << 16) | fetch_data[fb_dat].from_le()));
            fb_dat++;
        }
        else
            fetch_bundle[fb_idx].inst = new insn_t((insn_bits_t)((fetch_data[fb_dat].from_le())));
        *pc += fetch_bundle[fb_idx].inst->length();
        fb_dat++;
    }
    for (int i = 0; i < sizeof(fetch_bundle) / sizeof(fetch_bundle[0]); i++)
    {
        if (fetch_bundle[i].inst != nullptr)
            printf("PC: 0x%08x\topcode: 0x%08x\ticount=%d\n", fetch_bundle[i].pc, fetch_bundle[i].inst->bits(), fetch_bundle[i].inst_cnt);
    }
    printf("\n");
}