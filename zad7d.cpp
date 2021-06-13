#include <signal.h>
#include <string.h>
#include <iostream>

auto signal_handler(int, siginfo_t* info, void*) -> void {
	std::cout
	 <<"\n got signal:" << info->si_signo  << " from process with PID: " << info->si_pid<<"\n";
	
}

auto main() -> int {
	struct sigaction action;
	memset(&action, 0, sizeof(action));
	
	action.sa_sigaction = &signal_handler;
	action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, nullptr);

	while(1);
	return 0;
}

