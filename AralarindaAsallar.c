#include <stdio.h> 
#include <stdlib.h> 
#include <omp.h>
#include <stdbool.h>
  
int main(int argc, char* argv[]) 
{ 
   int bitisDegeri;
   printf("Bitiş değerini giriniz:");
   scanf("%d",&bitisDegeri);
   
   int kacAdetAralarindaAsalVar = 0;
   bool aralarindaAsalMi = true;
   double begin,end,time_spent;
   begin = omp_get_wtime();

       #pragma omp parallel for
           for(int i = 2; i< bitisDegeri; i++){
                for (int j = i+1 ; j <= bitisDegeri; j++)
                {
                    for (int k = 2; k <= i; k++)
                    {
                        if (((j % k == 0) && (i % k == 0))){
                            aralarindaAsalMi = false;
                            break;
                        }

                    }
                    if (aralarindaAsalMi)
                        kacAdetAralarindaAsalVar++;

                    aralarindaAsalMi = true;
                }
           }

        end = omp_get_wtime();
        time_spent = (end - begin);
        printf("Arasında asal olan sayıların adeti: %d\n",kacAdetAralarindaAsalVar);
        printf("Geçen süre %lf\n",time_spent);

    return (0);
} 