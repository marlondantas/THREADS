/*Programa que preencha um vetor com 50 números aleatórios e crie duas threads. A primeira fará a impressão dos 25 primeiros números (do 1o. ao 25o.) e a segunda os 25 restantes (do 50o. ao 26o.) */

#include <stdio.h>
#include <stdlib.h>

#include<time.h>

#include <pthread.h>

int vetortree[50];


void *lertree()
{
  int i;

  for (i = 0; i < 25; ++i)
  {

    printf("(via thread 1)O número na posicao %d é %d\n",i+1,vetortree[i]);

  }

  return 0;
}

void *lerlertree(){
  int i;

  for (i = 25; i < 50; ++i)
  {

    printf("(via thread 2)O número na posicao %d é %d\n",i+1,vetortree[i]);

  }

  return 0;
}

int THREADETREE(){

  int ii;

  for (ii = 0; ii < 50; ++ii)
  {
    vetortree[ii] = rand()%50;
  }

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

  execute = pthread_create(&linhas[0],NULL,lertree,NULL);

  srand(time(NULL));

  execute = pthread_create(&linhas[1],NULL,lerlertree,NULL);

  pthread_exit(NULL);

  return 0;

}