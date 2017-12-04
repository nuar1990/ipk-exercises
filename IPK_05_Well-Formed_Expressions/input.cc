#include <sstream>
#include <algorithm>
#include <iterator>

#include "input.hh"

std::string read_stream(std::istream& input)
{
  std::stringstream s;
  std::copy(
    std::istreambuf_iterator<char>(input),
    std::istreambuf_iterator<char>(),
    std::ostreambuf_iterator<char>(s)
    );
  return s.str();
}
