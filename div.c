#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
int main()
{
int fd0[2],fd1[2],pid,a;
char buff[20];
pipe(fd0);
pipe(fd1);
pid=fork();
if(pid==0)
{	close(fd0[0]);
	printf("Enter the value");
	scanf("%d",&a);
	write(fd0[1],(char*)&a,sizeof(a));
	wait(NULL);
	close(fd1[1]);
	read(fd1[0],(char*)buff,sizeof(buff));
	printf("%s",buff);
}
else
{
	close(fd0[1]);
	close(fd1[0]);
	read(fd0[0],(char*)&a,sizeof(a));
}
if(a%3==0)
	write(fd1[1],"divisible",sizeof("divisible"));
else
	write(fd1[1],"not divisible",sizeof("not divisible"));	
}

