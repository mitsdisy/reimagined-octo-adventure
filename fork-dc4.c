#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	pid_t p1;
	if(p1==0){
		pid_t p3;
		p3 = fork();
		if(p3 == 0){
			int i;
			for(i=0;i<10;i++){
				printf("p3 pid: %d, ppid: %d\n", getpid(),getppid());
				sleep(1);}
			return 0;}
		else if(p3 > 0){
			pid_t p2;
			p2 = fork();
			if(p2==0){
				pid_t p4;
				p4 = fork();
				if(p4 == 0){
					int i;
					for(i=0;i<10;i++){
						printf("p4 pid: %d, ppid: %d\n", getpid(),getppid());		
						sleep(1);}
					return 0;}
				else if(p4 >0){
					pid_t p5;
					p5 = fork();
					if(p5==0){
						int i;
						for(i=0;i<10;i++){
							printf("p5 pid: %d, ppid: %d\n", getpid(),getppid());
							sleep(1);}
						return 0;}
					else{//p2
						int i;
						for(i=0;i<10;i++){
							if(i==5)
								exit(1);
/*段错误
							if(i==5)
							{
								int *p=NULL;
								*p=0;
							}*/
							printf("p2 pid: %d, ppid: %d\n", getpid(),getppid());
							sleep(1);}
						return 0;}}}}
		int i;
		for(i=0;i<10;i++)
		{printf("p1 pid: %d, ppid: %d\n", getpid(),getppid());
			sleep(1);}
		return 0;}
	sleep(1);}
