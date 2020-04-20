SRC_DIR := src/main/java/com/craftinginterpreters/lox
SRC_FILES := $(wildcard $(SRC_DIR)/*.java)
TARGET = target/jlox-1.0-SNAPSHOT.jar

# Compile if timestamp of any source file is later than that of target
$(TARGET): $(SRC_FILES)
	@ mvn package

# Convenience target to build and run it.
run: $(TARGET)
	@ java -cp target/jlox-1.0-SNAPSHOT.jar com.craftinginterpreters.lox.Lox $(ARG)

help:
	@ echo 'make help:	shows this message'
	@ echo 'make: 		compiles jlox'
	@ echo 'make run: 	runs jlox'

# Tell make that "run" is not the name of a file.
.PHONY: run
