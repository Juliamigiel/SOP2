#include <sys/types.h>
#include <signal.h>
#include <cstdlib>

auto main(int argc, char* argv[]) -> int {
	
	auto pid_t = std::atoi(argv[1]);
	auto sig = std::atoi(argv[2]);
	
	kill(pid_t, sig); 
	
	return 0;
}


