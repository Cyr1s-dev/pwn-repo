# Compiler settings
CC = i686-w64-mingw32-gcc
CFLAGS = -fno-stack-protector
LDFLAGS = -Wl,--disable-dynamicbase,--disable-nxcompat

# File names
TARGET = vuln.exe
SOURCE = vuln.c

# Default target
all: $(TARGET)

# Compile the executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean