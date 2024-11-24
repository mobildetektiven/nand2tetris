#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <string>

enum Instruction_type
{
    A_INSTRUCTION = 0,
    C_INSTRUCTION,
    L_INSTRUCTION
};

class Parser
{
private:
    std::ifstream       assembly_file;
    static const size_t MAX_LINE_LENGTH = 200;
    char                next_line[MAX_LINE_LENGTH];
    char               *next_instruction;

public:
    Parser(char *file_name);
    bool             has_more_lines();
    void             advance_instruction();
    Instruction_type instruction_type() const;
    void             print_current_instruction();
    bool             is_instruction();
    std::string      symbol() const;
    char            *get_current_instruction();
};

#endif // PARSER_HPP