#include <stdio.h>
#include <string.h>

#include "tinyheap.h"

int main(void)
{
    char line[INPUT_SIZE];
    tinyheap_initialize();

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char command[16];
        int argument;
        int fields = sscanf(line, "%15s %d", command, &argument);

        if (fields == 1 && strcmp(command, "STATUS") == 0) {
            tinyheap_status();
        } else if (fields == 2 && strcmp(command, "ALLOC") == 0) {
            tinyheap_allocate(argument);
        } else if (fields == 2 && strcmp(command, "FREE") == 0) {
            tinyheap_free(argument);
        } else {
            puts("ERROR");
        }
    }

    return 0;
}
