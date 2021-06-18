#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

auto signal_handler(int, siginfo_t* info, void*) -> void {
	
    auto pathname="plik.txt";
    auto a = open(pathname,0);

    char buff[64]={0};
    read(a,buff,64);

    close(a);
}
auto main(int argc,char* argv[]) -> int {


auto pathname="plik.txt";

auto a = open(pathname,0);

char buff[64]={0};
read(a,buff,64);

close(a);

while(true){
std::cout<< buff << "\n";
sleep(1);
}
sigaction(SIGHUP,signal_handler );
while(1);
}


