#ifndef TINYHEAP_H
#define TINYHEAP_H

#define SLOT_COUNT 8
#define SLOT_BYTES 4
#define INPUT_SIZE 128

void tinyheap_initialize(void);
void tinyheap_allocate(int bytes);
void tinyheap_free(int start);
void tinyheap_status(void);

#endif
