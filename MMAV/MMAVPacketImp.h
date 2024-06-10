#pragma once

extern "C"
{
#include <libavformat/avformat.h>
}

class MMAVPacketImp
{
public:
    AVPacket *pkt;
};
