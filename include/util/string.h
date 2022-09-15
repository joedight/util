#pragma once

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char *rstrcpy(char *dst, const char *src)
{
        char *out = malloc(strlen(src) + 1);
        if (out) {
                strcpy(out, src);
        }
        free(dst);
        return out;
}

char *rstrcat(char *a, const char *b)
{
        size_t n = strlen(a) + strlen(b);
        char *out = malloc(n + 1);
        if (!out) {
                goto end;
        }

        strcpy(out, a);
        strcat(out, b);

end:
        free(a);
        return out;
}

char *rsprintf(char *str, const char *fmt, ...)
{
        va_list args;
        va_start(args, fmt);

        char *out = NULL;
        int n = vsnprintf(NULL, 0, fmt, args);
        if (n < 0) {
                goto end;
        }

        out = malloc(n + 1);
        if (!out) {
                goto end;
        }

        va_end(args);
        va_start(args, fmt);

        vsprintf(out, fmt, args);
end:
        va_end(args);
        free(str);
        return out;
}

