#include "decoder.h"

void Decoder::decode(Fetch *f)
{
    if (!f->is_fetch_queue_empty())
    {
        f->release_inst();
        f->release_inst();
    }
}
