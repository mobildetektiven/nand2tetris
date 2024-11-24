#include <iostream>
#include <string>
#include <cstring>

#include "parser.hpp"

Parser::Parser(char *file_name)
    : assembly_file(file_name)
{
    if (!assembly_file.is_open())
    {
        throw std::invalid_argument("Unable to open specified file");
    }
}

bool
Parser::has_more_lines()
{

    return (!(assembly_file.rdstate() & std::ifstream::eofbit));
}

void
Parser::advance_instruction()
{
    assembly_file.getline(next_line, MAX_LINE_LENGTH);
}
Instruction_type
Parser::instruction_type() const
{
    if (*next_instruction == '@')
    {
        return A_INSTRUCTION;
    }
    else if (*next_instruction == '(')
    {
        return L_INSTRUCTION;
    }
    return C_INSTRUCTION;
}

std::string
Parser::symbol() const
{

    std::string symbol;

    char *next_letter = next_instruction;
    next_letter++; // ignore the @ or ( char of the symbol
    while (*next_letter != '\0')
    {
        symbol.push_back(*next_letter);
        next_letter++;
        if (*next_letter == ')')
        {
            return symbol;
        }
    }
    return symbol;
}

void
Parser::print_current_instruction()
{
    std::cout << next_line << "\n";
}

bool
Parser::is_instruction()
{
    char *next_letter = next_line;
    for (int i = 0; i < MAX_LINE_LENGTH; i++)
    {
        if (*next_letter == '/' || *next_letter == '\0')
        {
            return false;
        }
        if (*next_letter != ' ')
        {
            next_instruction = next_letter;
            return true;
        }
        next_letter++;
    }
    return false;
}

char *Parser::get_current_instruction()
{
    return next_line;
}