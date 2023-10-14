/*
making a big comment block
*/

#include <cs50.h> // pre-processor directive, includes prototype for functions like get_string
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    strings are technically char *s since it is just an address of the first character
    double quotes take care of the adddress of variable

    pointer arithmetic

    typedef uint8_t BYTE;
    typedef char *string;

    char *s = "HI!"
    printf("%c", s[0]);
    printf("%c", s[1]);
    printf("%c\n", s[2]);
    printf("%c", *s);
    printf("%c", *(s+1));
    printf("%c\n", *(s+2));

    if i do
    string t = s; // sets string t to same address as s

    what we want to do is create a copy/duplicate string
    string t = malloc(strlen(s) + 1) // add 1 for the null character
    // malloc = memory allocation = how many bytes to allocate

    // copying s into t
    for (int i = 0, n = strlen(s); u <= n; i++)
    {
        t[i] = s[i];
    }
    strcopy(new_string, old_string);

    if (t == NULL) // means that no memory is available
    {
        return 1;
    }

    free(t); // giving back the memory that was malloc
    NULL = address 0 // wasted byte that the computer shouldn't use
    sizeof(int);
    int x = malloc(3*sizeof(int)); // basically makes x an array

    valgrind ./filename // checking memory allocation of code
    garbage values = values of variables that we did not proactively set ourselves
    passing by value = passing value of variable but not variable/address themselves, getting copies of values
    passing by reference = passing address + change permanently

    functions are called in a "stack" and are stackframes
    main -> swap -> other function, then is deleted till goes to main only
    heap goes down (when malloc is called), stack goes up (when functions called, ex. recursively)
    heap overflow + stack overflow + buffer overflow (using too much memory)

    int x;
    printf("x: ");
    scanf("%i", &x); // reading the text in the terminal and setting to address of x
    printf("x: %i\n", x);

    file I/O = input and output

    FILE *file = fopen("file_name.txt", "r");
    // FILE is type, "r" = read, "rb" = read binary, "w" = write, "wb" = write binary, "a" = append, input stores address of file
    if (file == NULL)
    {
        return 1;
    }
    fprintf(file, "%s,%s\n", "hello", "world");
    fclose(file);

    fread(buffer, 1, 4, input)
    buffer = used to store information

    BMP = bit map to store bytes as a map/grid (for images)

    typedef uin8_t BYTE;

    int main(int argc, char *argv[])
    {
        FILE *src = fopen(argv[1], "rb");
        FILE *dst = fopen(argv[2], "wb");

        BYTE b;

        while (fread(&b, sizeof(b), 1, src) != 0)
        {
            fwrite(&b, sizeof(b), 1, dst);
        }

        fclose(dst);
        fclose(src);
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void week_5()
{
    abstract data type = like data structure but w/ certain properties/characteristics up to coder how to implement
    - queue: FIFO = first in first out
        - enqueue = entering the queue
        - dequeue = exiting the queue
        - same order

    const int CAPACITY = 50;
    typedef struct
    {
        person people[CAPACITY];
        int size;
    } queue;

    - stack: LIFO = last in first out
        - ex. gmail, where most recent (last) emails show up first
        - push = adding to stack
        - pop = removing from stack
        - similar to queues, but need code to pop

    - arrays must remain contiguous
    - 
    typedef struct
    {
        person people[CAPACITY];
        int size;
    } stack;
}