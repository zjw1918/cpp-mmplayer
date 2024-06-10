#include "MMAV.h"

#include "MMAVPacketImp.h"
#include "MMAVReaderImp.h"

MMAVReader::MMAVReader()
{
    imp = new MMAVReaderImp();
    imp->formatCtx = avformat_alloc_context();
    const char * info = avutil_configuration();
    printf("ffmpeg info: %s\n", info);
}
MMAVReader::~MMAVReader()
{
    if (imp->formatCtx != nullptr)
    {
        avformat_free_context(imp->formatCtx);
        imp->formatCtx = nullptr;
    }

    if (imp != nullptr)
    {
        delete imp;
        imp = nullptr;
    }
}

int MMAVReader::Open(const char *path)
{
    if (imp->formatCtx == nullptr)
    {
        return -1;
    }

    int ret = avformat_open_input(&imp->formatCtx, path, nullptr, nullptr);
    if (!ret)
    {
        avformat_find_stream_info(imp->formatCtx, nullptr);
    }

    return ret;
}
int MMAVReader::Close()
{
    if (imp->formatCtx == nullptr)
    {
        return -1;
    }
    avformat_close_input(&imp->formatCtx);
    return 0;
}

int MMAVReader::Read(MMAVPacket *packet)
{
    if (imp->formatCtx == nullptr)
    {
        return -1;
    }
    int ret = av_read_frame(imp->formatCtx, packet->imp->pkt);
    return ret;
}