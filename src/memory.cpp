#include "memory.hpp"
#include <iostream>

HANDLE Memory::find_process(LPCSTR name) {
    HWND hWnd = FindWindow(NULL, name);
    
    if (hWnd == NULL) {
        fprintf(stderr, "Failed to find window. Error code: %d\n", GetLastError());
        exit(EXIT_FAILURE);
    }

    DWORD processId;
    GetWindowThreadProcessId(hWnd, &processId);

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

    if (hProcess == NULL) {
        fprintf(stderr, "Failed to open process. Error code: %d\n", GetLastError());
        exit(EXIT_FAILURE);
    }
    
    return hProcess;
}

