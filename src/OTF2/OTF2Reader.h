#include <string>

#include <otf2/otf2.h>

class OTF2Reader
{
public:
    OTF2Reader();
    OTF2Reader(const std::string& otf2_filename);
    ~OTF2Reader();

    void Open(const std::string& otf2_filename);
    void Close();

private:
    OTF2_Reader* reader;
};