# ? DETAILS
NAME = os-build
TYPE = iso

# executed before 'c' (empty means nothing)
DBG_CMD = break _kmain

# ? FLAGS
FLAG_LD = -T linker.ld
FLAG_CC = -g -O0 -ffreestanding -nostdlib -Isrc/include -Wall -Wextra

# ? PATHS
PATH_SRC = src
PATH_OUT = out
PATH_LIB = src/library
PATH_TMP = out/cache
FILE_OUT = $(PATH_OUT)/$(NAME).$(TYPE)

# ? TREES
TREE_BINARYS = $(PATH_TMP)/boot.bin $(PATH_TMP)/kernel.bin
TREE_OBJECTS = $(PATH_TMP)/kernel.asm.o $(TREE_LIBRARY) $(PATH_TMP)/kernel.c.o
TREE_LIBRARY = $(PATH_TMP)/memory.o $(PATH_TMP)/console.o

build: clean mkdir $(TREE_BINARYS)
	dd if=$(PATH_TMP)/boot.bin bs=512 count=1 > $(FILE_OUT)
	dd if=$(PATH_TMP)/kernel.bin >> $(FILE_OUT)
	dd if=/dev/zero bs=512 count=1 >> $(FILE_OUT)

run: build
	qemu-system-i386 -hda $(FILE_OUT)

debug: build
	gdb -ex "set confirm off" \
		-ex "set pagination off" \
		-ex "set disassembly-flavor intel" \
		-ex "set architecture i386:intel" \
		-ex "target remote | qemu-system-i386 -hda $(FILE_OUT) -S -gdb stdio" \
		-ex "add-symbol-file $(PATH_TMP)/kernel.asm.o 0x10000" \
		-ex "display/i \$$pc" \
		-ex "$(DBG_CMD)" \
		-ex 'c'

# ? FILES
# ** primary
$(PATH_TMP)/kernel.bin: $(TREE_OBJECTS)
	i686-elf-ld $(FLAG_LD) $(TREE_OBJECTS) -o $(PATH_TMP)/kernel.bin
$(PATH_TMP)/kernel.c.o:
	i686-elf-gcc $(FLAG_CC) -std=gnu99 -c $(PATH_SRC)/kernel.c -o $(PATH_TMP)/kernel.c.o
$(PATH_TMP)/kernel.asm.o:
	nasm -f elf -g $(PATH_SRC)/kernel.asm -o $(PATH_TMP)/kernel.asm.o
$(PATH_TMP)/boot.bin:
	nasm -f bin $(PATH_SRC)/boot.asm -o $(PATH_TMP)/boot.bin

# ** library
$(PATH_TMP)/console.o:
	i686-elf-gcc $(FLAG_CC) -std=gnu99 -c $(PATH_LIB)/console.c -o $(PATH_TMP)/console.o
$(PATH_TMP)/memory.o:
	i686-elf-gcc $(FLAG_CC) -std=gnu99 -c $(PATH_LIB)/memory.c -o $(PATH_TMP)/memory.o

# ? TOOLS
mkdir:
	mkdir -p $(PATH_TMP)
clean:
	rm -rf $(PATH_TMP)/*