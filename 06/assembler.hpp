#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include <fstream>
#include <string>
#include "parser.hpp"

class Assembler
{
private:
    char * file_name;
    Parser parser;

public:
    Assembler(char * file);
    void print_file_name();
    bool translate_assembly_file();
    std::string decode_instruction();
};

#endif // ASSEMBLER_HPP