#include <iostream>
#include <thread>
#include <unistd.h>


using namespace std;

void thread_fun1(){


    for(int i=1;i<100;i+= 2){
    
       sleep(1);    
       cout<<"Thread one cpp ===>"<<i<<endl;
 
       
    }

}

void thread_fun2(){


    for(int i=0;i<100;i+= 2){
       
       cout<<"Thread two cpp ===>"<<i<<endl;
       sleep(1);
    }

}

int main(){

    thread thread2(thread_fun2);
    thread thread1(thread_fun1);
    
    
    thread2.join();
    thread1.join();
    

return 0;
}
