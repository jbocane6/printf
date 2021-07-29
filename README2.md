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

This project contains four C files, a header, and a man page with all functions, prototypes, and descriptions you need to play with this version. Also the main file with some examples and use cases.  

To access the Man Page. ` man_3_printf ` directly in a terminal, download the file and move it to the directory /usr/share/man/man1 where the system stores man pages for User shell commands.  
You can view it by typing the following command: ` cd  /usr/share/man/man1 `  Otherwise into the project directory by typing `./man_3_printf `..


### How to use this project
  1. Please clone this repo into your sandbox or local terminal.  
  2. Access to the directory and compile all C files with the command: ` gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c - o _printf ` ( _printf is a suggested name, not mandatory)  
  3. Typing ./_printf shows all cases this program works with. Find all these cases in the ` main.c ` file. 
  4. For another test, please modify the main file considering the man-page description.  


### Flowchart
This project was thought to compile previous concepts such as Loops, Structures, Functions, and Variadic functions.
For better understanding you can access the logic behind the program as follows:

** The main functions is `int _printf(const char * const format, ...)` in the file `_printf.c ` **
This function evaluates the string input characters one by one looking for matching characters with de modifiers % and / if there is no coincidence just prints all strings without modifications.

<flowchart _printf>

<flowchart _printspecials>

<flowchart _printmod>
    <a href=#><img src="https://raw.githubusercontent.com/jbocane6/logos/main/Diagram_printf_function.png" /></a>
