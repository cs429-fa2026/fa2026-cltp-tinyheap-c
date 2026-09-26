# Tiny Heap CLTP

## Task

Debug `tinyheap.c` so its allocation commands follow the behavior below. Use GDB to investigate the failing behavior, then rebuild with `make`.

The program models a heap of 8 slots. Each slot holds 4 bytes. It reads one command per line from standard input:

- `ALLOC <bytes>` reserves the smallest number of contiguous slots needed, using first-fit. It prints `start=<slot>` on success, `FULL` if no contiguous space is available, and `ERROR` for a nonpositive or oversized request.
- `FREE <start>` frees the allocation that begins at that slot and prints `freed`. Invalid or already-freed starts print `ERROR`.
- `STATUS` prints `used=<slots> free=<slots>`.

Allocation sizes round up to the next whole slot. For example, `ALLOC 5` reserves two slots.

## Work in the terminal

Complete Git, GDB, and filesystem actions from the command line. Build and run the tests on your assigned UTCS Linux machine:

```sh
make
make check
```

Use GDB to investigate the behavior that does not match the specification, fix the implementation, and rerun `make check`. Save the output of your shell's `history` command to `shell_logs.txt`, then commit and push your changes.

The project uses standard C and builds from source on the target Linux machine. No prebuilt executable is required.
