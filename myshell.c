/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <Chen Pi, Mirical Williams Causton, Justin Lin, Do kyun Chang>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define

// Put global environment variables here

// Define functions declared in myshell.h here

Line tokenization(char* input, char* delim)
{
    int i = 0;
    char *token;
    Line command_line;

    // Collect the command from the input
    token = strtok(input, delim);
    strcpy(command_line.command, token);

    // If token has a newline, remove it
    if (command_line.command[strlen(command_line.command) - 1] == '\n')
    {
        command_line.command[strlen(command_line.command) - 1] = '\0';
    }

    // Collect the first arguments
    token = strtok(NULL, delim);

    // Loop to collect all arguments
    while (token != NULL)
    {
        // If token has a newline, remove it
        if (token[strlen(token) - 1] == '\n')
        {
            token[strlen(token) - 1] = '\0';
        }

        // Collect the next argument
        strcpy(command_line.arg[i], token);

        // increment to the next argument
        token = strtok(NULL, delim);
        i++;
    }
    return command_line;
}

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    Line command_line;

    // Parse the commands provided using argc and argv

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
        command_line = tokenization(buffer, DELIM);

        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command_line.command, "cd") == 0)
        {
            // your code here
        }

        // other commands here...
        
        // quit command -- exit the shell
        else if (strcmp(command_line.command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
    }
    return EXIT_SUCCESS;
}
