# Simple build of example and module

CC ?= gcc
CFLAGS ?= -Wall -Wextra -IInc

SRCS := $(wildcard Src/*.c) example/main.c
OBJS := $(SRCS:.c=.o)

# Optionally add logger stub if present
LOGGER_STUB := logger_stub.c
ifneq (,$(wildcard $(LOGGER_STUB)))
SRCS += $(LOGGER_STUB)
OBJS += $(LOGGER_STUB:.c=.o)
endif

TARGET := build/main


$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
