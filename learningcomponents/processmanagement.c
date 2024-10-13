#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        perror("Error in creating child process:\n");
        return EXIT_FAILURE;
    }else if(pid==0){
        printf("The child process is executing the the child process id is (PID:%d)\n",getpid());
    }else{
        printf("The parent process is executing the parent process id is(PID:%d)\n",getpid());
        wait(NULL);
        printf("The child process has finished executing:(PID=%d)\n",getpid());
        return 0;
    }
    
    return 0;
}