/*
Programa que crie duas threads, onde a a primeira deverá escrever dados em um vetor de 10 números inteiros e a segunda imprimir a média destes números
*/

#include <stdio.h>
#include <stdlib.h>

#include<time.h>

#include <pthread.h>

int vetor[10];


void *lertwo()
{
  int i;

  int total = 0;

  for (i = 0; i < 10; ++i)
  {
    total = total + vetor[i];
  }
  
  printf("O total é %d, ",total);
  printf("A média é %0.2f ",((double)total/10));
  
  return 0;
}

void *escrevertwo(){
  int i;

  for (i = 0; i < 10; ++i)
  {
    vetor[i] = rand()%10;
  }
  return 0;
}

int THREADETWO(){

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

  execute = pthread_create(&linhas[0],NULL,escrevertwo,NULL);

  srand(time(NULL));

  execute = pthread_create(&linhas[1],NULL,lertwo,NULL);

  pthread_exit(NULL);

  return 0;

}
