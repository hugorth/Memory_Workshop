/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *str = malloc(sizeof(char) * (strlen("Hello World") - 1));
    free(str);
    return 0;
}
