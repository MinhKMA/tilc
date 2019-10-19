#include <stdio.h>

void getMemoryInfo()
{
    FILE *meminfo = fopen("/proc/meminfo", "r");
    float totalMemory = 0;
    float freeMemory = 0;
    if(meminfo == NULL)
    {
        exit(-1);
    }
    char buff[256];
    while(fgets(buff, sizeof(buff), meminfo))
    {
        int ramKB;
        int ramfreeKB;
        if(sscanf(buff, "MemTotal: %d kB", &ramKB) == 1)
        {
            totalMemory = ramKB/1024;
            totalMemory = totalMemory/1024;
        }
        if(sscanf(buff, "MemFree: %d kB", &ramfreeKB) == 1)
        {
            freeMemory = ramfreeKB/1024;
            freeMemory = freeMemory/1024;
        }
    }
    if(fclose(meminfo) != 0)
    {
        exit(-1);
    }
    printf("Total Memory is %.2f: GB\n", totalMemory);
    printf("Free Memory is %.2f: GB\n", freeMemory);
}

void getCPULoad()
{
    float a,b,c;
    int e;
    char d[256];
    FILE *cpuload = fopen("/proc/loadavg", "r");
    if(cpuload == NULL)
    {
        exit(-1);
    }
    char buff[256];
    while(fgets(buff, sizeof(buff), cpuload))
    {
        sscanf(buff, "%f %f %f %s %d", &a,&b,&c,&d,&e);
        printf("Load avg in 1m is: %.2f\n", a);
        printf("Load avg in 5m is: %.2f\n", b);
        printf("Load avg in 15m is: %.2f\n", c);
    }
}

int main()
{
    printf("----------RAM---------\n");
    getMemoryInfo();
    printf("----------CPU---------\n");
    getCPULoad();
    printf("------------------------");

    return 0;
}
