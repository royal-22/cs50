#include <stdio.h>
#include <string.h>

int main(void)
{
   char *name[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

   for (int i = 0; i<7; i++)
   {
      if (strcmp(name[i], "Ron") == 0);
      {
         printf("Found\n");
         return 0;
      }
   }
   printf("Not found\n");
   return 1;
}
