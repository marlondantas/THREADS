/* Programa que crie duas threads responsáveis por gerar, 
simultaneamente, a seguinte série: 
12134256378491051112613147........ 
*/

#include <stdio.h>
#include <stdlib.h>

#include<time.h>

#include <pthread.h>

int vetorfive[50];

int sequencia(int fim){
  int a=1,b=1;

  int n=0;

  while (n<fim)
  {
    printf("a- %d -",a);
    a++;
    printf("a- %d -",a);
    a++;
    printf("b- %d -",b);
    b++;

    n++;
  }

  return 0;
}

void *lerfive()
{
  printf("\n(FIB Thread 1)\n");
  sequencia(100);

  return 0;
}

void *lerlerfive(){
  printf("\n(FIB Thread 2)\n");
  sequencia(100);

  return 0;
}

int THREADEFIVE(){

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

  execute = pthread_create(&linhas[0],NULL,lerfive,NULL);

  execute = pthread_create(&linhas[1],NULL,lerlerfive,NULL);

  pthread_exit(NULL);

  return 0;

}