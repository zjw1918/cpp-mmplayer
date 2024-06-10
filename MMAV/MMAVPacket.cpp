#include "MMAV.h"
#include "MMAVPacketImp.h"

MMAVPacket::MMAVPacket()
{
    imp = new MMAVPacketImp();
    imp->pkt = av_packet_alloc();
}
MMAVPacket::~MMAVPacket()
{
    if (imp->pkt != nullptr)
    {
        av_packet_free(&imp->pkt);
        imp->pkt = nullptr;
    }

    if (imp != nullptr)
    {
        delete imp;
        imp = nullptr;
    }
}
