/**
 * inotify.cpp
 *
 * Demonstrate the use of the inotify API.
 *
 * Usage: demo_inotify pathname...
 *
 * The program monitors each of the files specified on the command line for all
 * possible file events.
 *
 * This program is Linux-specific. The inotify API is available in Linux 2.6.13
 * and later.
 */


#include "../../StdTest.h"

#include <sys/inotify.h>

#include <limits.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <iostream>
#include <string>
#include <vector>
//-------------------------------------------------------------------------------------------------
// Display information from inotify_event structure
static void
displayInotifyEvent(struct inotify_event *i)
{
	printf("    wd =%2d; ", i->wd);
	if (i->cookie > 0) {
		printf("cookie =%4d; ", i->cookie);
	}

	printf("mask = ");

	if (i->mask & IN_ACCESS)        printf("IN_ACCESS ");
	if (i->mask & IN_ATTRIB)        printf("IN_ATTRIB ");
	if (i->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE ");
	if (i->mask & IN_CLOSE_WRITE)   printf("IN_CLOSE_WRITE ");
	if (i->mask & IN_CREATE)        printf("IN_CREATE ");
	if (i->mask & IN_DELETE)        printf("IN_DELETE ");
	if (i->mask & IN_DELETE_SELF)   printf("IN_DELETE_SELF ");
	if (i->mask & IN_IGNORED)       printf("IN_IGNORED ");
	if (i->mask & IN_ISDIR)         printf("IN_ISDIR ");
	if (i->mask & IN_MODIFY)        printf("IN_MODIFY ");
	if (i->mask & IN_MOVE_SELF)     printf("IN_MOVE_SELF ");
	if (i->mask & IN_MOVED_FROM)    printf("IN_MOVED_FROM ");
	if (i->mask & IN_MOVED_TO)      printf("IN_MOVED_TO ");
	if (i->mask & IN_OPEN)          printf("IN_OPEN ");
	if (i->mask & IN_Q_OVERFLOW)    printf("IN_Q_OVERFLOW ");
	if (i->mask & IN_UNMOUNT)       printf("IN_UNMOUNT ");

	printf("\n");

	if (i->len > 0)
		printf("        name = %s\n", i->name);
}
//-------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	if (argc < 2 || strcmp(argv[1], "--help") == 0) {
		printf("Usage: %s [PATH_NAME]\n", argv[0]);
		return EXIT_SUCCESS;
	}

	#define EVENT_SIZE (sizeof(struct inotify_event))
	#define BUF_LEN    ((EVENT_SIZE + NAME_MAX + 1) * 10)

	int iRv = 0;

	// Create inotify instance
	int inotifyFd = ::inotify_init();
	STD_TEST(inotifyFd != -1);

	// For each command-line argument, add a watch for all events
	std::vector<int> watchFds;

	for (int j = 1; j < argc; j++) {
		int watchFd = ::inotify_add_watch(inotifyFd, argv[j], IN_ALL_EVENTS);
		STD_TEST(watchFd != - 1);

		printf("Watching %s using wd %d\n", argv[j], watchFd);

		watchFds.push_back(watchFd);
	}

	// Read events forever
	for ( ; ; )  {
		char buf[BUF_LEN];

		ssize_t numRead = ::read(inotifyFd, buf, BUF_LEN);
		STD_TEST(numRead > 0);

		printf("Read %ld bytes from inotify fd\n", (long) numRead);

		// Process all of the events in buffer returned by read()
		for (char *p = buf; p < buf + numRead; ) {
			struct inotify_event *event = (struct inotify_event *) p;
			::displayInotifyEvent(event);

			p += EVENT_SIZE + event->len;
		}
	}

	for (size_t i = 0; i < watchFds.size(); ++ i) {
		iRv = ::inotify_rm_watch(inotifyFd, watchFds[i]);
		STD_TEST(iRv != -1)
	}

    iRv = ::close(inotifyFd);
    STD_TEST(iRv != -1);

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------
