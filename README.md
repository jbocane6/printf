<p align="center">
    <a href=#><img src="https://raw.githubusercontent.com/jbocane6/logos/main/holberton-logo.png" alt="holberton" /></a></p>
  
  <p align="center">
    <img align="center" src="https://avatars.githubusercontent.com/u/85180677?v=4" alt="Angela Vergara" height="120" width="120" />
    <a href="https://twitter.com/angelitaversa" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="twitter angela" height="30" width="40" /></a>
  <a href="https://www.linkedin.com/in/angela-vergara-salamanca" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="Linkedin angela" height="30" width="40" /></a>
  <a href="https://github.com/anversa-pro" target="blank"><img align="center" src="https://raw.githubusercontent.com/devicons/devicon/9f4f5cdb393299a81125eb5127929ea7bfe42889/icons/github/github-original.svg" alt="Github angela" height="30" width="40" /></a>
  &emsp;&emsp;&emsp;
  <img align="center" src="https://raw.githubusercontent.com/jbocane6/logos/main/foto.png" alt="juan" />
    <a href="https://twitter.com/juanoso07555284" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="juanoso07555284" height="30" width="40" /></a>
  <a href="https://linkedin.com/in/juan-camilo-bocanegra-osorio-18b1821a6" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="juan-camilo-bocanegra-osorio-18b1821a6" height="30" width="40" /></a>
  <a href="https://github.com/jbocane6" target="blank"><img align="center" src="https://raw.githubusercontent.com/devicons/devicon/9f4f5cdb393299a81125eb5127929ea7bfe42889/icons/github/github-original.svg" alt="Github juan" height="30" width="40" /></a>
  </p>  
  <br>
  <p align="center">
    <a href=#><img src="https://raw.githubusercontent.com/jbocane6/logos/main/titulo3.png" alt="titulo" /></a></p>

# PRINT FORMATTED: _printf
Printf function project performed by Angela Vergara &amp; Juan Bocanegra.  

_printf is an emulation of the original printf that refers to a control parameter used by a class of functions in the input/output libraries of C.  
A string is written, characters are usually copied literally into the function's output, but format specifier, which starts with a `%` character, indicate the location and method to translate a piece of data to characters or modifiers, starting with `\` character, indicates inline modifiers such as tab or newline.  


## About this Repo
#### Requirments to built it
  * Files should be compiled with gcc 4.8.4
  * No more than 5 functions per file
  * Files should end with a new line
  * No global variables allowed

This project contains four C files, a header, and a man-page with all functions, prototypes, and descriptions you need to play with this version.  

**C files**  
**_printf.c:**
_printf : This function evaluates the string input characters one by one looking for matching characters with de modifiers % and / to call a function for each case if there is no coincidence just prints all strings without modifications.  
*_printspecials : Search into a string of special modifiers to print the modifier (\n \t \b \f \v \r) or return the characters.
**_printmod.c**
pbuffer : Function that prints and delete chars in buffer.
p_intmin : Prints integers longer or equal than Min and Max integer limits.
p_int : Evaluates if the number is longer than integer limits and calls p-intmin otherwise prints integers calling _itoa
_itoa : converts an integer number into a string
_printmod : Search into a structure of specifiers (%c, %s, %d, %i, %R, %,r %b, %o, %x, %X) a function to print a format input
**_printcs.c**
p_char : Prints a char.
p_string : Prints strings.
p_reverse : Prints strings in reverse.
p_rot13 : Encodes a string using rot13.
**_printbases.c**
p_binary : converts a number into binary
p_octal : converts a number into octal
p_hexalow : converts a number into hexdecimal lowercase
p_hexaup : converts a number into hexdecimal uppercase

**Header**
holberton.h: This file contains prototypes for all the functions and the struct for data and function relation.

**Man-page**
man_3_printf : Custom man page for _printf function.

To access the Man Page. ` man_3_printf ` directly in a terminal, download the file and move it to the directory /usr/share/man/man1 where the system stores man pages for User shell commands.  
You can view it by typing the following command: ` cd  /usr/share/man/man1 `  Otherwise into the project directory by typing `./man_3_printf `..


### How to use this project
  1. Please clone this repo into your sandbox or local terminal.  
  2. Access to the directory and compile all C files with the command: ` gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c - o _printf ` ( _printf is a suggested name, not mandatory)  
  3. Typing ./_printf shows all cases set in the ` main.c ` file. 
  4. For another test, please modify the main.c file considering the man-page description.  

Example of main.c file:
>
>    #include <limits.h>
>    #include <stdio.h>
>    #include "holberton.h"
>
>    /**
>    * main - Entry point
>    *
>    * Return: Always 0
>    */
>    int main(void)
>    {
>        int len;
>        unsigned int ui;
>        void *addr;
>
>        len = _printf("Let's try to printf a simple sentence.\n");
>        ui = (unsigned int)INT_MAX + 1024;
>        addr = (void *)0x7ffe637541f0;
>        _printf("Length:[%d, %i]\n", len, len);
>        _printf("Negative:[%d]\n", -762534);
>        _printf("Unsigned:[%u]\n", ui);
>        _printf("Unsigned octal:[%o]\n", ui);
>        _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
>        _printf("Character:[%c]\n", 'H');
>        _printf("String:[%s]\n", "I am a string !");
>        _printf("Address:[%p]\n", addr);
>        len = _printf("Percent:[%%]\n");
>        _printf("Len:[%d]\n", len);
>        _printf("Unknown:[%r]\n");
>        return (0);
>    }
>

Expected results after compiling and executing:

>       Let's try to printf a simple sentence.
>       Length:[39, 39]
>       Negative:[-762534]
>       Unsigned:[2147484671]
>       Unsigned octal:[20000001777]
>       Unsigned hexadecimal:[800003ff, 800003FF]
>       Character:[H]
>       String:[I am a string !]
>       Address:[0x7ffe637541f0]
>       Percent:[%]
>       Len:[12]
>       Unknown:[%r]


### Flowchart
This project was thought to compile previous concepts such as Loops, Structures, Functions, and Variadic functions.
For better understanding you can access the logic behind the program as follows:

**The core function is `int _printf(const char * const format, ...)` in the file `_printf.c `**
This function evaluates the string input characters one by one looking for matching characters with de modifiers % and / if there is no coincidence just prints all strings without modifications.



<flowchart _printf>
<a href=#><img src="https://raw.githubusercontent.com/jbocane6/logos/main/Diagram_printf_function.png" /></a>

<flowchart _printspecials>


<flowchart _printmod>
