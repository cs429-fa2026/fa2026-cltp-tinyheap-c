# Compiler and flags
CC = gcc
CFLAGS = -W
DEBUG_FLAGS = -g -DDEBUG

# Directories
OUTPUT_DIR = outputs
BIN_DIR = bin

# Source and object files
READABLE_OBJ = $(BIN_DIR)/tinyheap.o
OBJ = $(BIN_DIR)/main.o
EXEC = $(BIN_DIR)/tinyheap

# The default target intentionally asks students to read this Makefile first.
.PHONY: default
default:
	echo "oops read the makefile!"

# Build the executable and object files.
all: $(BIN_DIR) $(OBJ) $(READABLE_OBJ)
	$(CC) $(OBJ) $(READABLE_OBJ) -o $(EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile each source file into bin/.
$(BIN_DIR)/%.o: %.c tinyheap.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Debug target (compiles with debug symbols).
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all

# Run every input case and print its output.
test: all
	@for testfile in testcases/*.in; do \
		echo "Running $$testfile..."; \
		./$(EXEC) < "$$testfile"; \
	done

# Compare every output with its expected result.
check: all
	@mkdir -p $(OUTPUT_DIR)
	@status=0; for testfile in testcases/*.in; do \
		base_name=$$(basename "$$testfile" .in); \
		./$(EXEC) < "$$testfile" > "$(OUTPUT_DIR)/$$base_name.out"; \
		if diff -u "testcases/$$base_name.expected" "$(OUTPUT_DIR)/$$base_name.out"; then \
			echo "PASSED $$testfile"; \
		else \
			echo "FAILED $$testfile"; \
			status=1; \
		fi; \
	done; exit $$status

# Remove generated build and test output.
clean:
	rm -f $(EXEC) $(OBJ) $(READABLE_OBJ)
	rm -rf $(OUTPUT_DIR)

.PHONY: all debug test check clean
