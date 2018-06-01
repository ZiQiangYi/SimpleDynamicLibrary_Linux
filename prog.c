#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "ctest.h"

int main(){

    void    *handle;
    char    *error;
    int     x,y,z;

    handle = dlopen("libctest.so.1", RTLD_LAZY);

    //The function dlopen() loads the dynamic shared object(shared library) file named by the null-terminated string filename and returns an opaque "handle" for the loaded object.
    //Perfom lazy binding. Resolve symbols only as the code that references them is executed. If the symbol is never referenced, then it is never resolved.
    if(!handle){
        fputs(dlerror(),stderr);
        exit(1);
    }

    ctest1 = dlsym(handle, "ctest1");
    //The function dlsym() takes a "handle" of a dynamic library returned by dlopen() and the null-terminated symbol name, returning the address where that symbol is loaded into memory.

    if((error = dlerror())!= NULL)
    {
        fputs(error, stderr);
        exit(1);
    }

    ctest2 = dlsym(handle, "ctest2");

    if((error = dlerror())!= NULL)
    {
        fputs(error, stderr);
        exit(1);
    }

    ctest1(&x);
    ctest2(&y);
    z=(y/x);
    printf("%d / %d = %d \n", x, y, z);

    dlclose(handle);
    //dlclose - close a dlopen object
    return 0;
}

