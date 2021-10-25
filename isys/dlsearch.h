#include <vector>
#include <iostream>

#include <dlfcn.h>

void run_ispp_lib(const char* fs, const char* entry)
{
    typedef void (*essential_t)();
    void *lib = dlopen(fs, RTLD_LAZY); //RTLD_LAZY=0x00001
    essential_t func = (essential_t) dlsym(lib,entry);
    func();
}