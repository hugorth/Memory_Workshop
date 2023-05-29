/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct metadata {
    size_t size;
    int is_free;
    struct metadata* next;
} metadata_t;

metadata_t* head = NULL;

void *my_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    size_t total_size = sizeof(metadata_t) + size;
    metadata_t *current_block = head;
    while (current_block != NULL) {
        if (current_block->is_free && current_block->size >= size) {
            current_block->is_free = 0;
            return (void *)(current_block + 1);
        }
        current_block = current_block->next;
    }
    void *block = sbrk(total_size);
    if (block == (void *) -1) {
        return NULL;
    }
    metadata_t *header = block;
    header->size = size;
    header->is_free = 0;
    header->next = head;
    head = header;
    return (void *)(header + 1);
}

int main(int argc, char *argv[]) {
    char *str = my_malloc(strlen("Hello World") + 1);
    strcpy(str, "Hello World");
    printf("%s\n", str);

    char *str_part_two = my_malloc(strlen("hello world") + 1);
    strcpy(str_part_two, "hello world");
    printf("%s\n", str_part_two);
    return 0;
}
