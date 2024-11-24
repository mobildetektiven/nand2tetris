#ifndef CODER_HPP
#define CODER_HPP

#include <string>

namespace Coder {
std::string Print_binary(uint16_t value, int num_bits = 15);
std::string Dest(char *code);
std::string Comp(char *code);
std::string Jump(char *code);
}

#endif // CODER_HPP