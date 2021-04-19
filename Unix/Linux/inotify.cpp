/**
 * \file  inotify.cpp
 * \brief inotify API
 *
 * Usage: demo_inotify [pathname]
 *
 * The program monitors each of the files specified on the command line for all
 * possible file events.
 *
 * This program is Linux-specific. The inotify API is available in Linux 2.6.13
 * and later.
 */


#include <StdTest.h>
#include <Stl.h>

#include <sys/inotify.h>
//-------------------------------------------------------------------------------------------------
// Display information from inotify_event structure
static void
inotifyEvent_print(struct inotify_event *a_ev)
{
	printf("    wd =%2d; ", a_ev->wd);
	if (a_ev->cookie > 0) {
		printf("cookie =%4d; ", a_ev->cookie);
	}

	printf("mask = ");

	if (a_ev->mask & IN_ACCESS)        printf("IN_ACCESS ");
	if (a_ev->mask & IN_ATTRIB)        printf("IN_ATTRIB ");
	if (a_ev->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE ");
	if (a_ev->mask & IN_CLOSE_WRITE)   printf("IN_CLOSE_WRITE ");
	if (a_ev->mask & IN_CREATE)        printf("IN_CREATE ");
	if (a_ev->mask & IN_DELETE)        printf("IN_DELETE ");
	if (a_ev->mask & IN_DELETE_SELF)   printf("IN_DELETE_SELF ");
	if (a_ev->mask & IN_IGNORED)       printf("IN_IGNORED ");
	if (a_ev->mask & IN_ISDIR)         printf("IN_ISDIR ");
	if (a_ev->mask & IN_MODIFY)        printf("IN_MODIFY ");
	if (a_ev->mask & IN_MOVE_SELF)     printf("IN_MOVE_SELF ");
	if (a_ev->mask & IN_MOVED_FROM)    printf("IN_MOVED_FROM ");
	if (a_ev->mask & IN_MOVED_TO)      printf("IN_MOVED_TO ");
	if (a_ev->mask & IN_OPEN)          printf("IN_OPEN ");
	if (a_ev->mask & IN_Q_OVERFLOW)    printf("IN_Q_OVERFLOW ");
	if (a_ev->mask & IN_UNMOUNT)       printf("IN_UNMOUNT ");

	printf("\n");

	if (a_ev->len > 0) {
		printf("        name = %s\n", a_ev->name);
	}
}
//-------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	if (argc < 2 || strcmp(argv[1], "--help") == 0) {
		printf("Usage: %s [PATH_NAME]\n", argv[0]);
		return EXIT_SUCCESS;
	}

	constexpr std::size_t EVENT_SIZE = sizeof(struct inotify_event);
	constexpr std::size_t BUF_LEN    = (EVENT_SIZE + NAME_MAX + 1) * 10;

	int iRv {};

	// Create inotify instance
	int inotifyFd = ::inotify_init();
	STD_TEST(inotifyFd != -1);

	// For each command-line argument, add a watch for all events
	std::vector<int> watchFds;
	{
		for (int j = 1; j < argc; ++ j) {
			int watchFd = ::inotify_add_watch(inotifyFd, argv[j], IN_ALL_EVENTS);
			STD_TEST(watchFd != - 1);

			printf("Watching %s using wd %d\n", argv[j], watchFd);

			watchFds.push_back(watchFd);
		}
	}

	// Read events forever
	for ( ; ; ) {
		char buff[BUF_LEN] {};

		const ssize_t numRead = ::read(inotifyFd, buff, BUF_LEN);
		STD_TEST(numRead > 0);

		printf("Read %zu bytes from inotify fd\n", numRead);

		// Process all of the events in buffer returned by read()
		for (char *p = buff; p < buff + numRead; ) {
			struct inotify_event *event = (struct inotify_event *)p;
			::inotifyEvent_print(event);

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
