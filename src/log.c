#include "include/common.h"
#include "include/log.h"

void error(char *s, int status)
{
    printf("%s, status: %d\n", s, status);
    exit(s);
}