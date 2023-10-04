/*
making a big comment block
*/

#include <cs50.h> // pre-processor directive, includes prototype for functions like get_string
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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
// 4. linking -> combining hello.c ; cs50.c ; stdio.c from binary, separate files into 1 file

// decompiling -> reverse engineering the compiled code
debug50 ./buggy  // debugs the code
string = array (can call [i] per character)
// strings have n+1 bytes w/ the +1 as a "\0" byte @ the end (equals to NUL)
// can initialize multiple variables in for loop

typedef struct
{
    string name;
    int age;
} person;

int main(void) // putting main code in, returns 0
{
    big o = worst case (upper bound) time it takes for algorithm
    Ω = best case
    Θ = best & worst case are the same
    linear search = O(n), Ω(1)
    binary search = O(logn), Ω(1)

    selection sort = select smallest and compare w/ rest, then swap
    --> (n-1) + (n-2) + (n-3) + (n-4) = (n)(n-1)/2 = n^2
    --> O(n^2), Ω(n^2), Θ(n^2)
    bubble sort = check and swap accordingly with the element behind
    --> (n-1)(n-1) = n^2
    --> O(n^2), Ω(n)
    merge sort = using recursion to cut in half and sort
    --> O(nlogn), Ω(nlogn), Θ(nlogn)

    recursion = function that calls itself (w/ smaller and smaller input)
    base case = breaking out of the recursion loop
}

int main(int argc, string argv[]) // putting main code in, returns 0
{
    argc = argument count = how many words did user type in prompt
    argv = argument vector = list of command line arguments
    argv[0] = name of the program
    echo $? shows the status code returned
    // cipher = algorithm for encrypting/scrambling messages, uses key
    // caesar cipher = move by 1, rot13 = move by 13
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


void fourth_week(int lazy)  // creating your own method/function
{
    RGB values represented via hexadecimal (or base-16)
    0 1 2 3 4 5 6 7 8 9 A B C D E F (okay if lowercase)
     #      #     #   #
    16^1  16^0 =  16  1  (FF = 255, multiply 16 and 1 by 15)
    2 hexademicals = 1 byte = 8 bits
    0x## prefaces that there is hexademical after

    %p shows address
    & returns address (pointer) of variable
    * going to the address

    int n = 50;
    int *p = &n; // declaring pointer and setting it to address of n
    printf("%p\n", p);
    printf("%i\n", *p);

    pointers take up 8 bytes (int takes up 4 bytes)

    string is pointer that points to the start of the array of characters
    strings are technically char *s

}