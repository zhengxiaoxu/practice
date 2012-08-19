CC = gcc

PROGS = print_threadid get_thread_exit_sta pthread_exit_err

print_threadid: print_threadid.o
	${CC} -o $@ print_threadid.o -lpthread

get_thread_exit_sta: get_thread_exit_sta.o
	${CC} -o $@ get_thread_exit_sta.o -lpthread

pthread_exit_err: pthread_exit_err.o
	${CC} -o $@ pthread_exit_err.o -lpthread

clean:
	rm -f ${PROGS} *.o core.* *.out core

