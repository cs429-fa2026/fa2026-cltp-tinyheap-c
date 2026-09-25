#include <stdio.h>
#include <string.h>

#define SLOT_COUNT 8
#define SLOT_BYTES 4
#define INPUT_SIZE 128

static int owner[SLOT_COUNT];
static int allocation_length[SLOT_COUNT];
static int free_slots;

static void initialize_heap(void)
{
    for (int i = 0; i < SLOT_COUNT; ++i) {
        owner[i] = -1;
        allocation_length[i] = 0;
    }
    free_slots = SLOT_COUNT;
}

static int slots_needed(int bytes)
{
    int needed = bytes / SLOT_BYTES;
    return needed > 0 ? needed : 1;
}

static void allocate_bytes(int bytes)
{
    if (bytes <= 0 || bytes > SLOT_COUNT * SLOT_BYTES) {
        puts("ERROR");
        return;
    }

    int needed = slots_needed(bytes);
    int start = -1;
    for (int candidate = 0; candidate <= SLOT_COUNT - needed; ++candidate) {
        int available = 1;
        for (int offset = 0; offset < needed; ++offset) {
            if (owner[candidate + offset] != -1) {
                available = 0;
                break;
            }
        }
        if (available) {
            start = candidate;
            break;
        }
    }

    if (start == -1) {
        puts("FULL");
        return;
    }

    for (int offset = 0; offset < needed; ++offset) {
        owner[start + offset] = start;
    }
    allocation_length[start] = needed;
    free_slots -= needed;
    printf("start=%d\n", start);
}

static void free_allocation(int start)
{
    if (start < 0 || start >= SLOT_COUNT || allocation_length[start] <= 0) {
        puts("ERROR");
        return;
    }

    int length = allocation_length[start];
    for (int offset = 0; offset < length; ++offset) {
        owner[start + offset] = -1;
    }
    allocation_length[start] = 0;
    free_slots += length;
    puts("freed");
}

int main(void)
{
    char line[INPUT_SIZE];
    initialize_heap();

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char command[16];
        int argument;
        int fields = sscanf(line, "%15s %d", command, &argument);

        if (fields == 1 && strcmp(command, "STATUS") == 0) {
            printf("used=%d free=%d\n", SLOT_COUNT - free_slots, free_slots);
        } else if (fields == 2 && strcmp(command, "ALLOC") == 0) {
            allocate_bytes(argument);
        } else if (fields == 2 && strcmp(command, "FREE") == 0) {
            free_allocation(argument);
        } else {
            puts("ERROR");
        }
    }

    return 0;
}
