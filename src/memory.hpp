#include <windows.h>
#include <iostream>

class Memory {
private:

    HANDLE find_process(LPCSTR name);    
    HANDLE hProcess;
        
public:
    // class constructor
    Memory(LPCSTR name) {
        this->hProcess = find_process(name);
    };

    // read process memory example:: int health = reader->read<int>(address);
    template <typename T>
    T read(uintptr_t address) {
        T buffer;
        if (ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, sizeof(buffer), nullptr) == 0) {
            fprintf(stderr, "Failed to read memory. Error code: %d\n", GetLastError());
            exit(EXIT_FAILURE);
        }        
        return buffer;
    }
    
    // int health = 100;
    // write process memory example:: reader->write<int>(address, health);
    template <typename T>
    void write(uintptr_t address, T buffer) {
        if (WriteProcessMemory(hProcess, (LPVOID)address, &buffer, sizeof(buffer), nullptr) == 0) {
            fprintf(stderr, "Failed to write to memory. Error code: %d\n", GetLastError());
            exit(EXIT_FAILURE);
        }
    }
    
};
