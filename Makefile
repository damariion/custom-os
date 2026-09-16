# ? DETAILS
NAME = os-build
TYPE = iso
ARCH = i386

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
TREE_BINARYS = $(PATH_TMP)/mbr.bin $(PATH_TMP)/kernel.bin
TREE_OBJECTS = $(PATH_TMP)/crt.o $(TREE_LIBRARY) $(PATH_TMP)/kernel.o
TREE_LIBRARY = $(PATH_TMP)/console.o

run: clean build
	qemu-system-$(ARCH) -hda $(FILE_OUT)

debug: clean build
	gdb -ex "set confirm off" \
		-ex "set pagination off" \
		-ex "set disassembly-flavor intel" \
		-ex "set architecture $(ARCH)" \
		-ex "target remote | qemu-system-$(ARCH) -hda $(FILE_OUT) -S -gdb stdio" \
		-ex "add-symbol-file $(PATH_TMP)/kernel.o 0x10020" \
		-ex 'c'

build: mkdir $(TREE_BINARYS)
	dd if=$(PATH_TMP)/mbr.bin bs=512 count=1 > $(FILE_OUT)
	dd if=$(PATH_TMP)/kernel.bin >> $(FILE_OUT)
	dd if=/dev/zero bs=512 count=1 >> $(FILE_OUT)

# ? FILES
# ** primary
$(PATH_TMP)/kernel.bin: $(TREE_OBJECTS)
	i686-elf-ld $(FLAG_LD) $(TREE_OBJECTS) -o $(PATH_TMP)/kernel.bin
$(PATH_TMP)/kernel.o:
	i686-elf-gcc $(FLAG_CC) -std=gnu99 -c $(PATH_SRC)/kernel.c -o $(PATH_TMP)/kernel.o
$(PATH_TMP)/crt.o:
	nasm -f elf $(PATH_SRC)/_crt.asm -o $(PATH_TMP)/crt.o
$(PATH_TMP)/mbr.bin:
	nasm -f bin $(PATH_SRC)/_mbr.asm -o $(PATH_TMP)/mbr.bin

# ** library
$(PATH_TMP)/console.o:
	i686-elf-gcc $(FLAG_CC) -std=gnu99 -c $(PATH_LIB)/console.c -o $(PATH_TMP)/console.o

# ? TOOLS
mkdir:
	mkdir -p $(PATH_TMP)
clean:
	rm -rf $(PATH_TMP)/*