#include <iostream>
#include <windows.h>

#include "memory.hpp"

#define WINDOW_NAME "AssaultCube"

int main() {
    
    Memory::find_process(WINDOW_NAME);

    uintptr_t address {0x00F76DD4};

    int health = Memory::read<int>(address);

    std::cout << health << std::endl;
    
    return 0;
}


