#include <stdio.h>

void MergeSort(int L[], int ini, int fin);
void Mezcla(int L[], int ini, int m, int fin);


int main(void)
{
   int inicio = 1, ultimo; 
   printf("De cuántos dígitos es tu lista? (menor de 10 dígitos) ");
   scanf("%d", &ultimo);
   int lista[10];
   printf("Escribe los números:  ");
   for (int i=inicio; i<=ultimo; i++)
   {
      scanf("%i", &lista[i]);
   }
   printf("\n");

   MergeSort(lista, inicio, ultimo);

   for(int j=inicio; j<=ultimo; j++)
   {
      printf("%d\t", lista[j]);
   }
   printf("\n");

   return 0;
}

void MergeSort(int L[], int ini, int fin)
{
   int m;
   m = (ini + fin)/2; 
   if(ini < fin)
   {
      MergeSort(L, ini, m);
      MergeSort(L, m+1, fin);
      Mezcla(L, ini, m, fin);
   }
}

void Mezcla(int L[], int ini, int m, int fin)
{
   int aux[20], i, j, k, t;

   k = 0;
   i=ini;
   j= m+1;

   //Ciclo que se va a encargar de hacer la mezcla
   while (i<= m && j<= fin)
   {
      k++;
      if(L[i] < L[j])
      {
         aux[k] = L[i];
         i++;
      }
      
      else 
      {
         aux[k] = L[j];
         j++;
      }
   }

   // Si quedarpn elementos en la primera sublista se los pasa
   for (t=i; t<=m; t++)
   {
      k++;
     aux[k]=L[t];
      k++;
   }

   // Si quedaron elementos en la primera sublista se los pasa
   for(t=j; j<=fin; t++)
   {
      k++;
      aux[k]=L[t];
      
   }

   // Se copia lo de la lista auxiliar (aux) a la lista original
   for(t=1; t<=k; t++)
   {
      L[ini+t-1] = aux[t];
   }
}


