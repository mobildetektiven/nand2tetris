#include "assembler.hpp"
#include "coder.hpp"

#include <stdexcept>
#include <iostream>
#include <fstream>

// std::string print_binary(uint16_t value) {
//    std::string line;
//    for (int i = 15; i >= 0; --i) {
//        line += ((value >> i) & 1) ? '1' : '0';
//    }
//    return line;
// }

Assembler::Assembler(char *file)
    : parser(file)
    , file_name(file) {};
void
Assembler::print_file_name()
{
    std::cout << file_name << "\n";
}

bool
Assembler::translate_assembly_file()
{
    // Logic that calls the parser and code object functions and builds the
    // binary

    std::ofstream output_file("binary.hack");
    while (parser.has_more_lines())
    {
        parser.advance_instruction();
        parser.print_current_instruction();
        if (parser.is_instruction())
        {
            output_file << decode_instruction();
        }
    }
    output_file.close();
    return true;
}

std::string
Assembler::decode_instruction()
{
    std::string symbol;
    u_int16_t   address = 0;
    std::string decode_line;
    std::string dest;
    std::string comp;
    std::string jump;

    switch (parser.instruction_type())
    {
        case C_INSTRUCTION:
            dest = Coder::Dest(parser.get_current_instruction());
            std::cout << dest << " Dest code\n";

            jump = Coder::Jump(parser.get_current_instruction());
            std::cout << jump << " JMP code\n";

            comp = Coder::Comp(parser.get_current_instruction());
            return "111" + comp + dest + jump + "\n";
            break;
        case L_INSTRUCTION:
        case A_INSTRUCTION:
            symbol = parser.symbol();
            // address = static_cast<uint16_t>(std::stoi(symbol));
            decode_line = Coder::Print_binary(address) + "\n";
            std::cout << decode_line;
            return decode_line;
        default:
            break; // exception that should not arise, handle by throwing
                   // exception?
    }
    return "";
}

// Function that handles the logic of decoding a each line of the input file

/*
    Check if current line is a instruction or not
    This means to discard all lines that starts with a null character or
   comments A line is an instruction if it is not a empty line or a comment, so
   I should jump to next line if the first character is null or the first non
   whitespace character is /

*/