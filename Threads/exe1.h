/*Programa que crie duas threads, onde a a primeira deverá escrever 
dados em um vetor de 10 números inteiros e a segunda imprimi-los 
*/

#include <stdio.h>
#include <stdlib.h>

#include<time.h>

#include <pthread.h>

int vetor[10];


void *ler()
{
  int i;

  for (i = 0; i < 10; ++i)
  {
    printf("%d ", vetor[i]);
  }
  return 0;
}

void *escrever(){
  int i;

  for (i = 0; i < 10; ++i)
  {
    vetor[i] = rand()%10;
  }

  return 0;
}

int THREADE(){

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

  execute = pthread_create(&linhas[0],NULL,escrever,NULL);

  execute = pthread_create(&linhas[1],NULL,ler,NULL);

  pthread_exit(NULL);

  return 0;

}
