/*
 * =====================================================================================
 *
 *       Filename:  print_threadid.c
 *
 *    Description:  print threadid
 *
 *        Version:  1.0
 *        Created:  08/19/2012 08:16:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhengxiaoxu (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_t ntid;

void
printids(const char *s)
{
	pid_t 		pid;
	pthread_t 	tid;
	
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
			(unsigned int)tid, (unsigned int)tid);
}

void *
thr_fn(void *arg)
{
	printids("new thread: ");
	return ((void *)0);
}

int
main(void)
{
	int 	err;
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if(err != 0)
		printf("can't create thread: %s\n", (char *)strerror(err));
	printids("main thread:");
	sleep(1);
	exit(0);
}
