#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
auto handler(int signo) -> void {
	std::cout << "create SIGCHLD\n";
	auto status=0;
    waitpid(-1, &status, 0);
	std::cout
		<< "with status: " << WEXITSTATUS(status) << "\n"; 
		exit(0);
	
}

auto main() -> int {
signal(SIGCHLD, handler);
	auto const children = fork();

	if( children == 0) {
std::cout << "im will be sleep now for 10s\n";
		sleep(10);
		exit(0);
        
	}
	std::cout << "create children " << children << "\n";
	

	while(true);

	return 0;
}
   

