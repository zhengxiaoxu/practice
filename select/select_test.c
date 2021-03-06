/************************************************
 * this programme to test select function.
 ************************************************/

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


void
display_time(const char *string)
{
	int seconds;
	seconds = time((time_t *)NULL);
	printf("%s %d\n", string, seconds);
}

int
main()
{
	fd_set 	readfds;
	struct 	timeval timeout;
	int 	ret;
	FD_ZERO(&readfds);
	FD_SET(0, &readfds);
	timeout.tv_sec 	= 10;
	timeout.tv_usec = 0;
	while(1)
	{
		display_time("before select");
		ret = select(1, &readfds, NULL, NULL, &timeout);
		display_time("after select");
		switch(ret)
		{
			case 0:
				printf("no data coming\n");
				exit(0);
			case -1:
				perror("select error\n");
				exit(1);
				break;
			default:
				getchar();
				printf("data is coming now!\n");
		}
	}
	return 0;
}






