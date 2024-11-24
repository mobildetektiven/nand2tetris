#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <cassert>

#include "coder.hpp"

const std::multimap<std::string, uint8_t> compMap
    = { { "0", 0b00101010 },   { "1", 0b00111111 },   { "-1", 0b111010 },
        { "D", 0b00001100 },   { "A", 0b0011000 },    { "M", 0b0011000 },
        { "!D", 0b00001101 },  { "!A", 0b00110001 },  { "!M", 0b00110001 },
        { "-D", 0b00001111 },  { "-A", 0b00110011 },  { "-M", 0b00110011 },
        { "D+1", 0b00011111 }, { "A+1", 0b00110111 }, { "M+1", 0b00110111 },
        { "D-1", 0b00001110 }, { "A-1", 0b00110010 }, { "M-1", 0b00110010 },
        { "D+A", 0b00000010 }, { "D+M", 0b00000010 }, { "D-A", 0b00010011 },
        { "D-M", 0b00010011 }, { "A-D", 0b00000111 }, { "M-D", 0b00000111 },
        { "D&A", 0b00000000 }, { "D&M", 0b00000000 }, { "D|A", 0b00010101 },
        { "D|M", 0b00010101 } };

std::string
Coder::Dest(char *code)
{
    uint16_t destination = 0;
    char * next_letter = code;
    while(*next_letter != '=')
    {
        if(*next_letter == 'M')
        {
            destination |= 1;
        }
        else if (*next_letter == 'D')
        {
            destination |= 2;
        }
        else if (*next_letter == 'A')
        {
            destination |= 4;
        }
        next_letter++;
    }

    if(*next_letter != '=')
    {
        destination = 0;
    }

    return Print_binary(destination, 3);

}

std::string
Coder::Comp(char* code)
{
    bool compSection = false;
    char* codeCpy = code;
    std::string comp;
    while (*code != '\0')
    {
        if (compSection)
        {
            comp += *code;
        }

        if (*code == '=' && !compSection)
        {
            compSection = true;
        }
        
        code++;
    }

    if (compSection == false)
    {
        while (*codeCpy != '\0')
        {
                if (*codeCpy == ';')
                {
                    break;
                }
                if (*codeCpy != ' ')
                {
                    comp += *codeCpy;
                }
                
                codeCpy++;
        }
    }

    auto it = compMap.find(comp);
    if (it != compMap.end())
    {
        return Print_binary(it->second, 6);
    }
    assert(false);
}

std::string
Coder::Jump(char* code)
{
    uint16_t jump = 0;

    if (strstr(code, "JGT"))
    {
        jump = 1;
    }
    else if (strstr(code, "JEQ"))
    {
        jump = 2;
    }
    else if (strstr(code, "JGE"))
    {
        jump = 3;
    }
    else if (strstr(code, "JLT"))
    {
        jump = 4;
    }
    else if (strstr(code, "JNE"))
    {
        jump = 5;
    }
    else if (strstr(code, "JLE"))
    {
        jump = 6;
    }
    else if (strstr(code, "JMP"))
    {
        jump = 7;
    }

    return Print_binary(jump, 3);
}

std::string
Coder::Print_binary(uint16_t value, int num_bits)
{
    std::string line;
    for (int i = num_bits - 1; i >= 0; --i)
    {
        line += ((value >> i) & 1) ? '1' : '0';
    }
    return line;
}