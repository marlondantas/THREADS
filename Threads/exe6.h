/* Programa que crie 3 threads para realizar as operações matemáticas básicas com matrizes quadradas: soma, subtração e multiplicação */

#include <stdio.h>
#include <stdlib.h>

#include<time.h>

#include <pthread.h>

void *soma(){
  int a = 10;
  int b = 20;
  printf("(THREAD 1)A soma dos números é %d\n",(a+b));
  return 0;
}

void *sub(){
  int a = 10;
  int b = 20;
  printf("(THREAD 2)A subtração dos números é %d\n",(a-b));
  return 0;
}

void *mul(){
  int a = 10;
  int b = 20;
  printf("(THREAD 3)A multplicacao dos números é %d\n",(a*b));
  return 0;
}


int THREADESIX(){

  pthread_t linhas[3];

  int execute,i;
   
  srand(time(NULL));

  // for (i=0;i<3;i++){
  //   v = (struct valor *) malloc(sizeof(struct valor *));
  //   v->tempo = (rand()%10);
  //   v->id = i;
  //   printf("Criei a thread <%d> com tempo <%d>\n",i,v->tempo);
  //   execute = pthread_create(&linhas[i],NULL,espera,(void *)v);
  // }

  execute = pthread_create(&linhas[0],NULL,soma,NULL);

  execute = pthread_create(&linhas[1],NULL,sub,NULL);

  execute = pthread_create(&linhas[2],NULL,mul,NULL);

  pthread_exit(NULL);

  return 0;

}