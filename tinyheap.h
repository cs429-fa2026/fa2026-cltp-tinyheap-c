#ifndef TINYHEAP_H
#define TINYHEAP_H

/* Heap capacity and allocation granularity. */
#define SLOT_COUNT 8
#define SLOT_BYTES 4
/* Maximum length of one command line. */
#define INPUT_SIZE 128

/* Initialize the heap before processing commands. */
void tinyheap_initialize(void);
/* Allocate bytes and print the first slot used. */
void tinyheap_allocate(int bytes);
/* Free an allocation by its starting slot. */
void tinyheap_free(int start);
/* Print the number of used and free slots. */
void tinyheap_status(void);

#endif
