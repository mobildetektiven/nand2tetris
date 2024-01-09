// Program: Mult
// Computes the product of the nubmers found in the R0 and R1 registers
// Usage, put the two values in the register and run the code

// If both register values are non-zero, the product is calculated by adding the 
// value of R0 to itself R1 times. 

    // Use two variables, sum is for calculating the product, i is the number of times 
    // to run the loop (R1) Initialize them to zero and R1
    @sum
    M=0
    @R1
    D=M
    @i
    M=D

    // Check for nonzero values in R0 and R1
    @R0
    D=M
    @STOP
    D;JEQ
    @R1
    D=M
    @STOP
    D;JEQ


// Add R0 to itself R1 times in a Loop
// Increse the value of Sum with R0
// Decrement the value of i
// if i == 0 goto stop 
(LOOP)
    // Evaluate the index and stop iteration if 0
    @i
    D=M
    @STOP
    D;JEQ

    // Add R0 to itself
    @R0
    D=M
    @sum
    M=D+M

    // Decrement the index
    @i
    M=M-1

    // Jump to top of loop
    @LOOP
    0;JMP

// Store the value of SUM in R2 and end program
(STOP)
    @sum
    D=M
    @R2
    M=D
    @END
    0;JMP