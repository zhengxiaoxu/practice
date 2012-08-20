/*
 * =====================================================================================
 *
 *       Filename:  pthread_clean_up.c
 *
 *    Description:  this programme to do pthread clean up
 *
 *        Version:  1.0
 *        Created:  08/20/2012 11:40:47 AM
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

void 
cleanup(void *arg)
{
	printf("cleanup: %s\n", (char *)arg);
}

void *
thr_fn1(void *arg)
{
	printf("thread 1 start\n");
	pthread_cleanup_push(cleanup, "thread 1 first handler");
	pthread_cleanup_push(cleanup, "thread 1 second handler");
	printf("thread 1 push complete\n");
	if (arg)
		return((void *)1);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	return((void *)1);
}

void *
thr_fn2(void *arg)
{
	printf("thread 2 start\n");
	pthread_cleanup_push(cleanup, "thread 2 first handler");
	pthread_cleanup_push(cleanup, "thread 2 second handler");
	pthread_cleanup_push(cleanup, "thread 2 third handler");
	printf("thread 2 push complete\n");
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(2);
	pthread_exit((void *)2);
}

int
main(void)
{
	int 		err;
	pthread_t 	tid1, tid2;
	void 		*tret;

	err = pthread_create(&tid1, NULL, thr_fn1, (void *)1);
	if (err != 0)
		printf("can't create thread 1:%s\n", (char *)strerror(err));
	
	err = pthread_create(&tid2, NULL, thr_fn2, (void *)2);
	if (err != 0)
		printf("can't create thread 2:%s\n", (char *)strerror(err));

	err = pthread_join(tid1, &tret);
	if (err != 0)
		printf("can't join with thread 1:%s\n", (char *)strerror(err));
	printf("thread 1 exit code %d\n", (int)tret);
	
	err = pthread_join(tid2, &tret);
	if (err != 0)
		printf("can't join with thread 2:%s\n", (char *)strerror(err));
	printf("thread 2 exit code %d\n", (int)tret);
	exit(0);
}








