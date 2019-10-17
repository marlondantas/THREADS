/*Programa que crie duas threads responsáveis por gerar, 
simultaneamente, a sequência de fibonacci: 
11235813213455...... 
 */


#include <stdio.h>
#include <stdlib.h>

#include<time.h>

#include <pthread.h>

int vetorfour[50];

// int fib(int valor){
//     int n=0;
//     long long int fb=0,fb2=1;
//     printf("0\n");
//     while (n<valor)
//     {
//         fb= fb+fb2;
//         fb2 = fb - fb2;
//         printf("%lld\n", fb);
//         n++;
//     }

//     return 0;
// }

void *lerfour()
{
  printf("FIB Thread 1");
  fib(100);

  return 0;
}

void *lerlerfour(){
  printf("FIB Thread 2");
  fib(100);

  return 0;
}

int THREADEFOUR(){
  pthread_t linhas[2];

  int execute,i;
   
  srand(time(NULL));

  // for (i=0;i<3;i++){
  //   v = (struct valor *) malloc(sizeof(struct valor *));
  //   v->tempo = (rand()%10);
  //   v->id = i;
  //   printf("Criei a thread <%d> com tempo <%d>\n",i,v->tempo);
  //   execute = pthread_create(&linhas[i],NULL,espera,(void *)v);
  // }

  execute = pthread_create(&linhas[0],NULL,lerfour,NULL);

  srand(time(NULL));

  execute = pthread_create(&linhas[1],NULL,lerlerfour,NULL);

  pthread_exit(NULL);

  return 0;

}