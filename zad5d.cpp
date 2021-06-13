#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>

auto main() -> int {
int status;
for(int i=0;i<4;i++) 
    {
int random= (rand() % 11);


        if(fork() == 0)
        { 
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
            std::cout<<"i will sleep:"<<random<<" sec\n";
            sleep(random);
            int randwork=(rand()% 2);
            std::cout<<"[son] pid: "<<getpid()<<" choos:"<<randwork<<"\n";
            exit(0);

        }
    }
    for(int i=0;i<4;i++){ 
     if (WIFEXITED(status)==true) {
        printf("The process ended with kill -%d.\n", WTERMSIG(status));
 if(fork() == 0){
            int random2= (rand() % 11);
            printf("[son] pid after error %d from [parent] pid %d\n",getpid(),getppid());
            std::cout<<"i will sleep:"<<random2<<" sec\n";
            sleep(random2);
            int randwork2=(rand()% 2);
            std::cout<<"[son] pid: "<<getpid()<<" choos:"<<randwork2<<"\n";
            exit(0);

}
                }
    wait(NULL);
}
}


