#ifndef _FUNCTION_POINTERS_
#define _FUNCTION_POINTERS_

#include <stdlib.h>

void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));

#endif
