CC = gcc



print_threadid: print_threadid.o
	${CC} -o $@ print_threadid.o -lpthread


get_thread_exit_sta:get_thread_exit_sta.o
	${CC} -o $@ get_thread_exit_sta.o -lpthread
clean:
	rm -f *.o core.* *.out core

