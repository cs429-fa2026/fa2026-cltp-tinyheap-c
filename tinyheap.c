#include <stdio.h>
#include <string.h>

#include "tinyheap.h"

static int owner[SLOT_COUNT];
static int allocation_length[SLOT_COUNT];
static int free_slots;

void tinyheap_initialize(void)
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

void tinyheap_allocate(int bytes)
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

void tinyheap_free(int start)
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

void tinyheap_status(void)
{
    printf("used=%d free=%d\n", SLOT_COUNT - free_slots, free_slots);
}

