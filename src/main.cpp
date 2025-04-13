#include <iostream>
#include <windows.h>

#include "memory.hpp"

#define WINDOW_NAME "AssaultCube"

int main() {

    Memory *reader = new Memory(WINDOW_NAME);

    uintptr_t address {0x00F76DD4};

    
    
    return 0;
}


