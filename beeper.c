#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#if defined(WIN32) || defined(_WIN32)
    #include <windows.h>
    #define sleep(x) Sleep(x)
    #define MULTI 1000
#else
    #include <unistd.h>
    #define MULTI 1
#endif
#define TRUE 1
#define FALSE 0
volatile sig_atomic_t loop = FALSE;

void change_state(int sig) {
    loop = FALSE;
}

int main(int argc, char **argv) {
    long time = 10;
    for(int i=1;i<argc;i++) {
        if(!strcmp("--help",argv[i])||!strcmp("-h",argv[i])){
            printf(
                "-h|--help - shows this message\n"
                "-l|--loop <time|10> - keeps the program running indefinitely, repeating every <time> seconds\n");
            exit(0);
        }
        if(!strcmp("--loop",argv[i])||!strcmp("-l",argv[i])) {
            loop = TRUE;
            if(argc > i) {
                long l_time = strtol(argv[i+1],NULL,10);
                if(l_time > 0) {
                    time = l_time;
                }
            }
        }
    }
    signal(SIGINT, change_state);
    do {
        printf("\a");
        fflush(stdout);
        sleep(time*MULTI);
    } while(loop);
    return 0;
}