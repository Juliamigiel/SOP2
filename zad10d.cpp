#include <iostream>
#include <sys/types.h>
#include <unistd.h>

auto main() -> int {
uint32_t ptr = 0x23570432;
        const uint32_t PAGE_OFFSET_MASK{0x00000FFF};
        uint32_t pageOffset = (ptr & PAGE_OFFSET_MASK) >> 0;
        std::cout << std::hex << pageOffset << '\n';
const uint32_t SECOND_OFFSET_MASK{0x003FF000};
        uint32_t secondLevelPage = (ptr & SECOND_OFFSET_MASK) >> 12;
        std::cout << std::hex << secondLevelPage << '\n';
	return 0;
}
