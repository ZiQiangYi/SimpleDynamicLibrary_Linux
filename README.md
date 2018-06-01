# SimpleDynamicLibrary_Linux
Explain how to build and use dynamic library(.so) on Linux.

Here's the code for compilation of our "ctest" library and "prog" program:

  gcc -Wall -fPIC -c ctest1.c ctest2.c

  gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0 ctest1.o ctest2.o

  ln -sf libctest.so.1.0 libctest.so.1

  gcc -Wall -o prog cprog.c -ldl

  export LD_LIBRARY_PATH=.

  ./prog



Reference:

[gcc] command

-shared

  Produce a shared object which can then be linked with other objects to form an executable. Not all systems support this option. For predictable results, you must also specify the same set of options used for compilation (-fpic, -fPIC, or model suboptions) when you specify this linker option.

-Wl,option

  Pass option as an option to the linker. If option contains commas, it is split into multiple options at the commas. You can use this syntax to pass an argument to the option. For example, -Wl,-Map,output.map passes -Map output.map to the linker. When using the GNU linker, you can also get the same effect with -Wl,-Map=output.map. 

what -ldl specifies?

  It tells the linker to link the dl library, which is located at /usr/lib/libdl.so. -l is the switch to add a library, dl is the name of it (without the lib prefix or .so extension).
  

[ln] command is a standard Unix command utility used to create a hard link or a symbolic link (symlink) to an existing file

ln [-fs] [-L|-P] source_file target_file

-f Force existing destination pathnames to be removed to allow the link.

-s Create symbolic links instead of hardlinks. 

*In this repository, you can not find libctest.so.1. You can create this by [ln] command. "prog.c" load this file.  
