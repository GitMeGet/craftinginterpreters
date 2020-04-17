# Compile the .c file to an executable.
linked_list: DoublyLinkedList.c
	gcc -g DoublyLinkedList.c -o linked_list

# Convenience target to build and run it.
run: linked_list
	@ ./linked_list

# Tell make that "run" is not the name of a file.
.PHONY: run
