#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LENGTH 20
#define PCREAD pc_fd[0]
#define PCWRITE pc_fd[1]
#define CPREAD cp_fd[0]
#define CPWRITE cp_fd[1]

int main(int argc, char *argv[]){
	int pc_fd[2], cp_fd[2];
	pid_t cpid;
	char buf[LENGTH];
	
	if (argc != 2){//????
		fprintf(stderr, "Usage: <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (pipe(pc_fd) == -1) {//check if pipe errored, create pipe
		perror("pipe");
		exit(EXIT_FAILURE);
	}	
	if (pipe(cp_fd) == -1) {//check if pipe errored, create pipe
		perror("pipe");
		exit(EXIT_FAILURE);
	}	
	cpid = fork(); //create new fork, cpid = PID of child
	if (cpid == -1){//check if fork failed, in which case no process is created
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0){//check if this is the child
		read(PCREAD, &buf, LENGTH);
		printf("Parent read in message from argv: %s\n", buf);
		write(CPWRITE, buf, LENGTH);
		close(CPWRITE);
		exit(EXIT_SUCCESS);
	}
	else {
		close(PCREAD);// close unused read end to write
		write(PCWRITE, argv[1], LENGTH);
		close(PCWRITE);
		printf("Parent read in message from argv[]: %s\n", argv[1]);
		wait(NULL);
		read(CPREAD, &buf, LENGTH); //write from argv to buffer 
		printf("%s\n", buf);
		close(CPREAD);
		exit(EXIT_SUCCESS);
	}
	return 0;
}

