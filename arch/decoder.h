#pragma once

#include "../processor.h"
#include "fetch.h"

class Decoder
{
public:
    void decode(Fetch *f);
    Decoder()
    {
    }
};