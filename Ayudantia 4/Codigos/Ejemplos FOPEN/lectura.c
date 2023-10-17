#include <stdio.h>
#include <stdlib.h>

int main () {
   FILE * fp;
   int c;
   fp = fopen("file.txt", "r");
   while((c=fgetc(fp)) != EOF)
   {
       printf("%c", c);
   }
   printf("\n");
   fclose(fp);
   
   return(0);
}

