// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen
// by writing 'black' in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen by writing
// 'white' in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Init global variable
    @8192
    D=A
    @screen_size
    M=D

(MAIN_LOOP)
    // Check if any keyboard buttons are pressed, jump to BLACK if pressed,
    // otherwise jump to WHITE
    @KBD
    D=M
    @BLACK
    D;JGT
    @WHITE
    0;JMP



(BLACK)
    // Reset indexer used to iterate over all screen registers
    @i
    M=0

    (BLACK_LOOP)
    //Check if loop is complete
    @i
    D=M
    @screen_size
    D = D-M
    @MAIN_LOOP
    D;JEQ

    //Write screen word for current index
    @i
    D=M
    @SCREEN
    A=A+D
    M=-1

    //Increment index
    @i
    M=M+1

    //goto top
    @BLACK_LOOP
    0;JMP

(WHITE)
    // Reset indexer used to iterate over all screen registers
    @i
    M=0

    (WHITE_LOOP)
    //Check if loop is complete
    @i
    D=M
    @screen_size
    D = D-M
    @MAIN_LOOP
    D;JEQ

    //Write screen word for current index
    @i
    D=M
    @SCREEN
    A=A+D
    M=0

    //Increment index
    @i
    M=M+1

    //goto top
    @WHITE_LOOP
    0;JMP
    
    
