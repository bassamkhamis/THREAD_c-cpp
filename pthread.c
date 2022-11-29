#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


pthread_mutex_t mutex;

pthread_cond_t vR = PTHREAD_COND_INITIALIZER;


void *thread_fun1(){


    for(int i=1;i<100;i+= 2){
    
       sleep(1);    
       pthread_mutex_lock(&mutex);
       printf("Thread one ===> %d\n",i);
       pthread_mutex_unlock(&mutex);
       
       
       
    }

}

void *thread_fun2(){


    for(int i=0;i<100;i+= 2){
       
       pthread_mutex_lock(&mutex);
       printf("Thread two ===> %d\n",i);
       
       pthread_mutex_unlock(&mutex);
       sleep(1);
    }

}

int main(){

     pthread_t th1_id, th2_id;
     
     int ret2 = pthread_create(&th2_id,NULL,&thread_fun2,NULL);
    // sleep(1);
     int ret1 = pthread_create(&th1_id,NULL,&thread_fun1,NULL);
     
     // main wait untill all threads terminate
     
     pthread_join(th2_id, NULL);
     pthread_join(th1_id, NULL);


return 0;
}
