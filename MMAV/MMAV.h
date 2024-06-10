#pragma once

class MMAVPacketImp;
class MMAVReaderImp;

class MMAVPacket
{
public:
    MMAVPacket();
    ~MMAVPacket();
    MMAVPacketImp *imp = nullptr;
};

class MMAVReader
{
private:
    MMAVReaderImp * imp = nullptr;
public:
    MMAVReader();
    ~MMAVReader();

    int Open(const char *path);
    int Close();

    int Read(MMAVPacket *packet);
};