/**
 * \file  SignalTest.cpp
 * \brief
 *
 * \review
 *
 * Compile with:
 * cc -I/usr/local/include -o signal-test \
 *   signal-test.c -L/usr/local/lib -levent
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <sys/types.h>

#include <event2/event-config.h>

#include <sys/stat.h>
#ifndef _WIN32
#include <sys/queue.h>
#include <unistd.h>
#include <sys/time.h>
#else
#include <winsock2.h>
#include <windows.h>
#endif
#include <signal.h>
#include <fcntl.h>

#include <event2/event.h>
//--------------------------------------------------------------------------------------------------
int called = 0;
//--------------------------------------------------------------------------------------------------
static void
signal_cb(evutil_socket_t fd, short event, void *arg)
{
	(void)fd;
	(void)event;

	struct event *signal = static_cast<struct event *>(arg);

	printf("signal_cb: got signal %d\n", event_get_signal(signal));

	if (called >= 2)
		event_del(signal);

	called++;
}
//--------------------------------------------------------------------------------------------------
int
main(int, char **)
{
	struct event *signal_int;
	struct event_base* base;

#ifdef _WIN32
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);

	(void) WSAStartup(wVersionRequested, &wsaData);
#endif

	/* Initalize the event library */
	base = event_base_new();

	/* Initalize one event */
	signal_int = evsignal_new(base, SIGINT, signal_cb, event_self_cbarg());

	event_add(signal_int, NULL);

	event_base_dispatch(base);
	event_free(signal_int);
	event_base_free(base);

	return 0;
}
//--------------------------------------------------------------------------------------------------
