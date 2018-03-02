/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#ifndef MYSHELL_H_
#define MYSHELL_H_

// Include your relevant functions declarations here they must start with the 
// extern keyword such as in the following example:
// extern void display_help(void);
#define BUFFER_LEN 256
#define DELIM " "

typedef struct line_t
{
    char command[BUFFER_LEN];
    char arg[][BUFFER_LEN];
} Line;

#endif /* MYSHELL_H_ */