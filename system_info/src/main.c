#include <stdio.h>

#include <windows.h>
#include <sysinfoapi.h>

#include "utils.h"


int main() {
    SYSTEM_INFO processor_info;
    MEMORYSTATUSEX memory_info;
    memory_info.dwLength = sizeof(MEMORYSTATUSEX);

    GetSystemInfo(&processor_info);
    GlobalMemoryStatusEx(&memory_info);

    print_title("CPU");
    printf("Arch: %s\n", get_arch_name(processor_info.wProcessorArchitecture));
    printf("Processor number: %d\n", processor_info.dwNumberOfProcessors);

    print_title("MEMORY");
    printf("Total: %lf\n", bytes_to_gigabytes(memory_info.ullTotalPhys));
    printf("Available: %lf\n", bytes_to_gigabytes(memory_info.ullAvailPhys));
    printf(
        "Usage: %0.1lf%\n",
        get_percent(
            memory_info.ullTotalPhys - memory_info.ullAvailPhys,
            memory_info.ullTotalPhys
        )
    );
}
