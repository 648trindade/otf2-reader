#include "OTF2Reader.h"
#include <stdexcept>

OTF2Reader::OTF2Reader(){}

OTF2Reader::OTF2Reader(const std::string& otf2_filename)
{
    this->Open(otf2_filename);
}

OTF2Reader::~OTF2Reader()
{
    if (this->reader)
        this->Close();
}

void OTF2Reader::Open(const std::string& otf2_filename)
{
    this->reader = OTF2_Reader_Open(otf2_filename.c_str());
    if (this->reader == nullptr)
        throw std::runtime_error("Error opening OTF2 file: " + otf2_filename);
}

void OTF2Reader::Close()
{
    if (this->reader)
    {
        OTF2_Reader_Close(this->reader);
        this->reader = nullptr;
    }
}