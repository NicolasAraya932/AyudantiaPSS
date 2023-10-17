#include <stdarg.h>
#include <stdio.h>

double average(int count, ...)
{
    va_list ap;
    int j;
    double sum = 0;

    va_start(ap, count); /* Requiere el último argumento */
    for (j = 0; j < count; j++) {
        sum += va_arg(ap, int); /* Incremente el iterador al siguiente argumento */
                                /* Iterador, Tipo */
    }
    va_end(ap);

    return sum / count;
}

int main(int argc, char const *argv[])
{
	printf("%f\n", average(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) );
	printf("%f\n", average(6, 1, 2, 3, 4, 5, 6) );
    return 0;
}
