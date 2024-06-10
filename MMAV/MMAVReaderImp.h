#pragma once

extern "C"
{
#include <libavformat/avformat.h>
}

class MMAVReaderImp
{
public:
    AVFormatContext *formatCtx;
};