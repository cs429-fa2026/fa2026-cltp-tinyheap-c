# cs429-mastery-assignment

# Please uninstall all AI tooling before beginning.

## [IMPORTANT] After you SSH into a lab machine: Note that

  * ALL git commands must be in the command line.
  * ALL gdb debugging must be in the command line.
  * ALL file system actions (eg. creating a file, navigating a file, etc) must be in the command line

You are allowed to utilize the terminal of your choice for these actions, but they must be accomplished in-terminal.
Note: SSHing and opening this repo via VS Code or another GUI is acceptable provided that the above actions are then accomplished via a terminal therein.

# What this repo contains:

  * `tinyheap.c` and its corresponding header file, and precompiled .o files in `bin/`.
  * A reference executable named `ref_tinyheap`.
  * A Makefile
  * Some testcases in the `testcases` folder

# What this code does:

The given code takes in an arbitrary number of lines of the format `<ACTION> <argument>`. The command driver parses each line; the implementation in `tinyheap.c` is responsible for the heap behavior and may not be correct. It models a heap with 8 slots, each holding 4 bytes. `ALLOC <bytes>` reserves contiguous slots, `FREE <start>` releases an allocation, and `STATUS` reports the number of used and free slots. The object files in `bin/` and the reference executable are functional.

Conceptual view (not exact program output):

```text
8 slots × 4 bytes = 32 bytes

slot:  0  1  2  3  4  5  6  7
      [ ][ ][ ][ ][ ][ ][ ][ ]

Example: ALLOC 7 needs 2 adjacent slots, reserving 8 bytes.
```

Running `./ref_tinyheap` or `./bin/tinyheap` without options in a terminal starts interactive mode. The program prints `Enter commands:` and shows `TH>` before each command. Try `STATUS`, `ALLOC <bytes>`, or `FREE <start>`; press Ctrl-D to finish. Use `-i <file>` to process commands from a file.

# Instructions:

1. ssh into your favorite UTCS lab machine
2. Clone this repository
3. Read then use the Makefile
4. Debug the test cases using gdb; you must use gdb to pass this assessment.
5. To the best of your ability, ensure your output matches the reference exactly.
6. Write the outputs of the `history` command to a file in this repo called `shell_logs.txt`
7. Commit and push your changes. Do not forget to add `shell_logs.txt` to git.
8. Run `./DELETE_REPO` to clean up the repository (or simply delete the repository directory yourself manually via the command line). Note this does not commit nor push your changes to any remote.
