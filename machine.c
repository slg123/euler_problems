#include <stdio.h>
#include <sys/utsname.h>

int main()
{
    struct utsname u;
    uname(&u);

    const char *sysname = u.sysname;
    const char *nodename = u.nodename;
    const char *release = u.release;
    const char *version = u.version;
    const char *machine = u.machine;

    printf("%s %s %s %s %s\n", u.sysname, u.nodename, u.release,
                               u.version, u.machine ); 

    return 0;
}
