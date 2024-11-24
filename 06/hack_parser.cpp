#include <iostream>
#include "assembler.hpp"

using namespace std;

enum
{
    max_line_length = 200
};

int
main(int argc, char **argv)
{

    
    if (argc < 2)
    {
        cout << "Missing input .asm file, ending program \n";
        return 0;
    }

    Assembler assembler(argv[1]);
    assembler.print_file_name();
    assembler.translate_assembly_file();

    return 1;

    // char *file_name = argv[1];
    // cout << "Opening file: " << file_name << "\n";
    // ifstream file(file_name);

    // if (!file.is_open())
    // {
    //     cout << "Unable to open file\n";
    //     return 0;
    // }

    // char next_line[max_line_length];
    // while (!(file.rdstate() & ifstream::eofbit))
    // {
    //     file.getline(next_line,max_line_length);
    //     cout << next_line << "\n";
    // }

    // cout << "Finished reading file \n";

}

