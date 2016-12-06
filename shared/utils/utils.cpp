#include "utils/utils.h"
#include <random>
#include <iostream>

using namespace std;

class CLogBuf : public std::streambuf
{
public:
  std::streamsize xsputn(const char_type *s, std::streamsize n)
  {
    return n;
    cout.write(s, n);
    return n;
  }
  int_type overflow(int_type c)
  {
    return c;
    cout.put(c);
    return c;
  }
};

const _Settings Settings;
ostream cdebug(new CLogBuf());

ACSData
utils::newACSData()
{
  return std::move(ACSData(new std::array<byte, 64>()));
}

_Settings::_Settings()
{
  // This will eventually load settings from a config file or Redis
}