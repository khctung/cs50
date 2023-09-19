/*
making a big comment block
*/

#include <cs50.h> // pre-processor directive, includes prototype for functions like get_string
#include <stdio.h>

void method_name(int parameter); // need to define function before main
                                 // called prototype
const int constant = 0;

rename("old_name", "new_name"); // rename a file
code name.c  // creates file
make name    // compiles file
             // is an abstraction itself, so is compiling
./ name      // runs file

clang hello.c // computer runs compiler
./a.out       // stores file as a and is used to run it

clang -o hello hello.c  // cmomputer runs compiler and stores as hello
./hello                 // runs hello
clang -o hello hello.c -lcs50 // l = library you're using, then the name of it

// converting source code to machine code
// 1. pre-processing -> using #include to call prototypes for functions
// 2. compiling -> converting coded language to assembly language
// 3. assembling -> converts assmembly language to binary
// 4. linking -> 

int main(void) // putting main code in, returns 0
{

}

void method_name(int parameter)  // creating your own method/function
{

}

// for loop is good for when you know # times repeating
// while loop is good for continuous operations when condition is true
// do-while is good for continuous operations that need to be run at least once

5/3 = 1 // c rounds down, floor
int type_casting = 0;
float casted = (float) type_casting;
printf("%.6f", casted) // shows 6 digits after decimal point
// format code for long is %li = long integer
// double = more precision bc more #s after decminal point
// truncation occurs when integer divided by integer
// floating point imprecision = cannot represent infinite #s in universe
// integer overflow = not enough memory to store large integers
