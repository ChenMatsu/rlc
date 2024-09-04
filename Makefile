# ----------------------------------------------------------------
# Environments
CC	=	gcc

# ----------------------------------------------------------------
# Options
CFLAGS	=	-Wall -Wextra -std=c99 -I$(INCLUDE_DIR)

# ----------------------------------------------------------------
# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# ----------------------------------------------------------------
# Sources
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) \
			$(wildcard $(SRC_DIR)/algorithms/*.c) \
			$(wildcard $(SRC_DIR)/common/*.c) \
			$(wildcard $(SRC_DIR)/environments/*.c) \
			$(wildcard $(SRC_DIR)/neural_networks/*.c) \
			$(wildcard examples/*.c)

# ----------------------------------------------------------------
# Objects
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# ----------------------------------------------------------------
# Library name
LIB_NAME = librlc.a

# ----------------------------------------------------------------
# Executable name
EXEC_NAME = rlc

# ----------------------------------------------------------------
# Default Targets
all: ${BIN_DIR}/${EXEC_NAME}

# ----------------------------------------------------------------
# Rule to create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# ----------------------------------------------------------------
# Rule to create library
${BIN_DIR}/${LIB_NAME}: ${OBJ_FILES}
	@mkdir -p $(BIN_DIR)
	ar rcs $@ $^

# ----------------------------------------------------------------
# Rule to create executable
${BIN_DIR}/${EXEC_NAME}: ${OBJ_FILES}
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm

# ----------------------------------------------------------------
# Clean
clean:
	rm -rf ${OBJ_DIR} ${BIN_DIR}

