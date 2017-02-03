# isAlpha

The object of this lab is to write the TINY code necessary to implement a function named isalpha. The function
should not depend upon global variables or global constants; and it should not use labels that could conflict with
labels defined in the main function or any other function of a program.

You need to also write a main function in TINY that will test this function. For instance, does the function work
correctly if the incoming parameter contains a non-ASCII value? However, do not submit your main function. The
instructor will use his own copy of a main function. The TINY source code you submit should only contain the
isalpha function.

Remember to use C++ statements to document your assembler code. In addition, you should include a header
documentation that lists the function name, your name, and a brief description of what the function accomplishes.

Function prototype: int isalpha(char c)

The isalpha function should accept one argument, the ASCII code for a character (passed by value via the system
stack). The function should return (via the ACC) the integer 1 if the character is an alphabetic letter (lowercase or
uppercase); otherwise the function should return the value 0.

BE SURE THAT YOUR ENTRY LABEL AGREES WITH THE FUNCTION NAME LISTED ABOVE. That is,
the start of the executable code in the function should be:
isalpha:
