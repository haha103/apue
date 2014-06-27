#include "apue.h"
#include <pthread.h>
#include <sys/syscall.h>

pthread_t ntid;

void printids(const char * s)
{
	pid_t pid, pid2;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	pid2 = syscall(SYS_gettid);
	printf("%s: pid %u, pid2 %u, tid %lu (0x%lx)\n", s, (unsigned int)pid, (unsigned int)pid2, (unsigned long)tid, (unsigned long) tid);
}

void * thr_fn(void * arg)
{
	printids("new thread:  ");
	sleep(15);
	return ((void *)0);
}

int main(int argc, char * argv [])
{
	int err;

	if ((err = pthread_create(&ntid, NULL, thr_fn, NULL)) < 0)
		err_sys("pthread_create error");

	printids("main thread: ");
	sleep(20);
	
	return EXIT_SUCCESS;
}
