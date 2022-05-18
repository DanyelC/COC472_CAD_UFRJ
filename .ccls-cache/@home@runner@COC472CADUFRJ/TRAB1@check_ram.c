#include <stdio.h>
#include <sys/sysinfo.h>

void printmemsize(char *str, unsigned long ramsize) {
        printf("%s: %ld in bytes / %ld in KB / %ld in MB / %ld in GB\n",str, ramsize, ramsize/1024, (ramsize/1024)/1024, ((ramsize/1024)/1024)/1024);
}

int main(int argc, char **argv) {
        struct sysinfo info;
        sysinfo(&info);
        printf("uptime: %ld\n", info.uptime);
        // print total ram size
        printmemsize("totalram", info.totalram);
        printmemsize("freeram", info.freeram);
        printmemsize("sharedram", info.sharedram);
        printmemsize("bufferram", info.bufferram);
        printmemsize("freeswap", info.freeswap);
        printf("current running processes: %d\n", info.procs);
        return 0;
}