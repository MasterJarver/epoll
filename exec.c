#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	char Buffer[50];
	printf("Insert progname:");
	scanf("%s",Buffer);
	execl("/usr/bin/find","find","/","-name",Buffer,(char*)0);
	return 0;
}