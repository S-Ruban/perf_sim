#include "fetch.h"

void fetch(processor_t *cpu, memif_t *memory, reg_t *pc)
{
    reg_t fetch_bundle_pc = *pc;
    target_endian<uint16_t> fetch_data[4];
    for (int i = 0; i < sizeof(fetch_data) / sizeof(target_endian<uint16_t>); i++)
        fetch_data[i] = memory->read_uint16(*pc + (i << 1));
    // printf("%x %x %x %x\n", fetch_data[0], fetch_data[1], fetch_data[2], fetch_data[3]);
    struct fetch_bundle fb = {
        {0x0},
        {0x0},
        {0xffffffff}};
    int fb_dat = 0, fb_idx = 0;
    while (fb_idx < 4)
    {
        if (fb_dat > sizeof(fb.pc) / sizeof(fb.pc[0]) - 1)
            break;
        fb.pc[fb_idx] = fetch_bundle_pc + ((fb_dat) << 1);
        fb.ic[fb_idx] = ic_cntr;
        ic_cntr++;
        // printf("%d %d %x %x %x ", fb_dat, fb_idx, fetch_data[fb_dat].from_le(), fetch_data[fb_dat].from_le() & (uint16_t)0x3, *pc);
        if ((fetch_data[fb_dat].from_le() & (uint16_t)0x3) == 0x3)
        {
            if (fb_dat == 3)
                break;
            fb.opcode[fb_idx] = (fetch_data[fb_dat + 1].from_le() << 16) | fetch_data[fb_dat].from_le();
            // printf("%08x\n", (fetch_data[fb_dat + 1].from_le() << 16) | fetch_data[fb_dat].from_le());
            fb_dat += 2;
            *pc += 0x2;
        }
        else
        {
            fb.opcode[fb_idx] = (fetch_data[fb_dat].from_le());
            // printf("%08x\n", (fetch_data[fb_dat].from_le()));
            fb_dat += 1;
        }
        *pc += 0x2;
        fb_idx++;
    }
    for (int i = 0; i < sizeof(fb.pc) / sizeof(fb.pc[0]); i++)
    {
        if (fb.opcode[i])
            printf("PC: 0x%08x\topcode: 0x%08x\ticount=%d\n", fb.pc[i], fb.opcode[i], fb.ic[i]);
    }
    printf("\n");
}