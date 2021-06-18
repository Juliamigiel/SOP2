#include <sys/types.h>
#include <signal.h>
#include <cstdlib>


auto main(int argc, char* argv[]) -> int {
	
	auto pid_t = std::atoi(argv[1]);
	auto sig = std::atoi(argv[2]);

 union sigval {
               int   sival_int;
               void *sival_ptr;
           };
	
	sigqueue(pid_t, sig, sigval); 
	
	return 0;
}


