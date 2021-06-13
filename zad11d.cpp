#include <unistd.h>
# include <sys/mman.h>
#include <linux/bpf.h>
auto main() -> int {
auto const page = mmap ( 
nullptr
, 4096
, PROT_READ
, MAP_PRIVATE | MAP_ANONYMOUS
, -1
, 0);

munmap ( page , 4096); 

	return 0;
}
