#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <string.h>

int (*orig)(int, const char *, int) = NULL;

int unlinkat(int dirfd, const char *pathname, int flags)
{
    orig = dlsym(RTLD_NEXT, "unlinkat");
    if (strstr(pathname, "FIX") != 0)
    {
        return EPERM;
    }
    return orig(dirfd, pathname, flags);
}
    
