
# Set optimization level for entire project
CXXFLAGS = 0

parser : hack_parser.o assembler.o parser.o coder.o
	g++ -o parser hack_parser.o assembler.o parser.o coder.o

hack_parser.o : hack_parser.cpp assembler.hpp
	g++ -c -g hack_parser.cpp 

assembler.o : assembler.cpp assembler.hpp parser.hpp coder.hpp
	g++ -c -g assembler.cpp

parser.o : parser.cpp parser.hpp
	g++ -c -g parser.cpp

coder.o : coder.cpp coder.hpp
	g++ -c -g coder.cpp

clean:
	rm *.o hack_parser