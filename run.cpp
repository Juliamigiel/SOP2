#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
pid_t cpid;
void handler(int i){
kill(cpid,i);
}
 auto main (int argc, char *argv[]) -> int
{

  auto cpid = fork();
  if (cpid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (cpid == 0) {
    execvp(argv[1], argv + 1);
    perror("execve");
    exit(EXIT_FAILURE);
  }

struct sigaction act{};
act.sa_handler = handler;
sigaction(SIGTERM, &act, nullptr);

signal(SIGINT, SIG_IGN);
int status = 0;
waitpid(cpid,&status,0); 

if(WIFEXITED(status)){
std::cout<<"Process: " <<cpid << "status: "<<WEXITSTATUS(status)<<"\n";
}
if(WIFSIGNALED(status)){
std::cout<<"Process: " <<cpid << "Killed by signal: "<<WTERMSIG(status)<<"\n"<<strsignal(WTERMSIG(status))<< "\n";
}
  return 0;
}
