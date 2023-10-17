#include <stdio.h>
#include <stdlib.h>

int main () {
   FILE * fp = fopen("file.txt", "w+");

   fprintf(fp, "%s", "HOLA");
   
   fclose(fp);
   
   return(0);
}

