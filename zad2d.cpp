#include <iostream>
#include <sys/types.h>
#include <unistd.h>

auto main() -> int {
	auto a=fork();
    if(a==0){
std::cout << "ppid:"<< getpid()<< "\n";
}
else{
	std::cout <<"npid:"<< a << "\n";
}	


	return 0;
}
