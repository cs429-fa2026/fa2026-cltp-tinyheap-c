# cs429-mastery-assignment

# Please uninstall all AI tooling before beginning.

## [IMPORTANT] After you SSH into a lab machine: Note that

  * ALL git commands must be in the command line.
  * ALL gdb debugging must be in the command line.
  * ALL file system actions (eg. creating a file, navigating a file, etc) must be in the command line

You are allowed to utilize the terminal of your choice for these actions, but they must be accomplished in-terminal.
Note: SSHing and opening this repo via VS Code or another GUI is acceptable provided that the above actions are then accomplished via a terminal therein.

# What this repo contains:

  * `tinyheap.c` and `tinyheap.h`, which implement and declare a small fixed-size heap model.
  * A Makefile
  * Some testcases and expected outputs in the `testcases` folder
  * `DELETE_REPO`, a script to clean up this local repository after you commit and push your work

# What this code does:

The given code reads lines of the format `<ACTION> <argument>` in `tinyheap.c`. It models a heap containing 8 slots, each holding 4 bytes. `ALLOC <bytes>` reserves contiguous slots using first-fit, `FREE <start>` frees an allocation, and `STATUS` reports the number of used and free slots. Allocation sizes round up to whole slots. The implementation may not be correct, and it is up to you to fix it. The expected outputs are in the `testcases` folder.

# Instructions:

1. ssh into your favorite UTCS lab machine
2. Clone this repository
3. Read then use the Makefile
4. Debug the test cases using gdb; you must use gdb to pass this assessment.
5. To the best of your ability, ensure your output matches the expected output exactly.
6. Write the outputs of the `history` command to a file in this repo called `shell_logs.txt`
7. Commit and push your changes. Do not forget to add `shell_logs.txt` to git.
8. Run `./DELETE_REPO` to clean up the repository (or simply delete the repository directory yourself manually via the command line). Note this does not commit nor push your changes to any remote.
