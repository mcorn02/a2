Team Names: Michael Corn and Simmon Quan

Edoras Usernames: cssc1415 and cssc1450

Assignment #2: Experimental Shell "XHS"

File Name: XSH.cpp

File Manifest: XSH.cpp, XSH.h. Makefile, README.txt

Compile Instructions: To compile the program using the Makefile (make command), input make then ./xsh and valid commands.

Operating Instructions: Provide files, programs, and valid commands. Valid commands must follow the format cssc0000% __ | __, replace __ with a valid shell command.
Commands can have unlimited arguments as long as each argument is separated by the pipe symbol |.

Design Decisions: While designing this program, we decided to only create and reuse two pipes when needed instead of creating a unique new pipe for every | symbol within the input.
We made this design decision because if we reuse previously created pipes for input that has multiple | symbols, we can lower system overhead by reducing the amount of system calls and better manage system resources.
We also modularized each operation such as tokenizing the command string, trimming white space, creating/managing the pipelines and child processes into separate functions to simplify the readability of the main method. 
Tokenizing the input in its own function allowed for simplified conversion of commands and arguments into the char* array needed for the exec function.

No non-required features/functionality was added.

To our knowledge, all known deficiencies/bugs were fixed during testing.
The most major error we had to fix was the shell printing out username/prompt for the first command as intended, but it would not print after encountering an invalid input.
We fixed this issue by flushing the buffer. 
There was also the issue of parsing the input. We use a split_pipes function to split commands if needed and a tokenize_commands function to split arguments. 

Lessons Learned: Through this project we learned how to create I/O pipes, how to reduce overhead by reusing existing I/O pipes,
how to create and manage child processes using fork, and how to parse the input via tokenizing the input string.

Pair Programming: Programming for this project was done together via live screen sharing sessions. 

split_pipes(): written by Simmon Quan with input from Michael Corn. 

tokenize_commands(): written by Simmon Quan with input from Michael Corn.

create_pipes(): written by Michael Corn with input from Simmon Quan.

trim(): written by Simmon Quan with input from Michael Corn.

run_pipelines(): written by Michael Corn with input from Simmon Quan.

run_shell(): written by Michael Corn with input from Simmon Quan.

main(): written by Michael Corn with input from Simmon Quan.

README: Written by Simmon Quan with input from Michael Corn. 
