# Compile the Java file to a class file.
HelloWorld.class: HelloWorld.java
	@ javac HelloWorld.java

# Convenience target to build and run it.
run: HelloWorld.class
	@ java HelloWorld

# Tell make that "run" is not the name of a file.
.PHONY: run
