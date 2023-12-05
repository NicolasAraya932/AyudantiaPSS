#include <fcntl.h>
/*Dependiendo del sistema Unix, seran o no
*requeridos los siguientes headers
*/
#include <sys/types.h>
#include <sys/stat.h>

int open(const char *path, int oflags); 
int open(const char *path, int oflags, mode_t mode);