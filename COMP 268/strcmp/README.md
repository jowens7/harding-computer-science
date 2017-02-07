The object of this lab is to write the TINY code necessary to implement a function named strcmp.  The function should not depend upon global variables or global constants; and it should not use labels that could conflict with labels defined in the main function or any other function of a program. 
 
You need to also write a main function in TINY that will test this function.  For instance, does the function work correctly if the incoming parameters contain an empty (null) string?  However, do not submit your main function.  The instructor will use his own copy of a main function.  The TINY source code you submit should only contain the strcmp function.
 
Remember to use C++ statements to document your assembler code.  In addition, you should include a header documentation that lists the function name, your name, and a brief description of what the function accomplishes.
 
Function prototype:        int strcmp (char string1[], char string2[])
 
The strcmp function should accept two arguments, the address of two strings (passed by reference via the stack). The function should then compare string2 and string1 lexigraphically.  That is, compare the ASCII values of the first two characters of the two strings.  If they are different, return the difference (i.e. string1[0] – string2[0]); otherwise skip to the next two characters.  Be sure to account for different length strings.
 
The function's returned value should be 0 if the two strings are identical, a negative value if string1 < string2 and a positive value if string1 > string2.  The negative or positive value should be the actual difference in ASCII values of the non-identical characters  (string1[i] – string2[i]).
 
 
BE SURE THAT YOUR ENTRY LABEL AGREES WITH THE FUNCTION NAME LISTED ABOVE.  That is, the first label in the strcmp function should be:
 
strcmp:
 
ALSO, just to be clear, your strcmp function should not perform any I/O.  All input and output functions should reside in the main function.
 
Here is an example of a test run using a program named, test_strcmp, that combines strcmp with a temporary main function;
 
 ```
$ run test_strcmp
Enter two strings
String1? How now brown cow
String2? How now brown cow
Return value = 0, thus String1 == String2
 
Enter two strings
String1? ABC
String2? ABD
Return value = -1, thus String1 < String2
 
Enter two strings
String1? Z
String2? ABCDE
Return value = 25, thus String1 > String2
 
Enter two strings
String1?                  I entered a null string (just a carriage return)
String2? ABC
Return value = -65, thus String1 < String2
 
Enter two strings
String1? ABCD
String2? ABC
Return value = 68, thus String1 > String2
```
