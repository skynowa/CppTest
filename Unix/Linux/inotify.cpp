/**
 * \file  main.cpp
 * \brief
 */


#include "../../StdTest.h"

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <sys/types.h>
#include <sys/inotify.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
//-------------------------------------------------------------------------------------------------
int main( int argc, char **argv )
{

    char buffer[BUF_LEN];

    int fd = ::inotify_init();
    STD_TEST(fd > 0);

    int wd = ::inotify_add_watch(fd, "./test.txt", IN_ALL_EVENTS);
    STD_TEST(wd > 0);

    int length = ::read(fd, buffer, BUF_LEN);
    STD_TEST(length >= 0)
    std::cout << STD_TRACE_VAR(length) << std::endl;

    int i = 0;

    while ( i < length ) {
        struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];
        if ( event->len ) {
        #if 0
            if ( event->mask & IN_CREATE ) {
                if ( event->mask & IN_ISDIR ) {
                    printf( "The directory %s was created.\n", event->name );
                }
                else {
                    printf( "The file %s was created.\n", event->name );
                }
            }
            else if ( event->mask & IN_DELETE ) {
                if ( event->mask & IN_ISDIR ) {
                    printf( "The directory %s was deleted.\n", event->name );
                }
                else {
                    printf( "The file %s was deleted.\n", event->name );
                }
            }
            else if ( event->mask & IN_MODIFY ) {
                if ( event->mask & IN_ISDIR ) {
                    printf( "The directory %s was modified.\n", event->name );
                }
                else {
                    printf( "The file %s was modified.\n", event->name );
                }
            }
        #endif
            if ( event->mask & IN_ACCESS ) {
                std::cout << STD_TRACE_VAR(IN_ACCESS) << std::endl;
            }
            if ( event->mask & IN_ATTRIB ) {
                std::cout << STD_TRACE_VAR(IN_ATTRIB) << std::endl;
            }
            if ( event->mask & IN_CLOSE_WRITE ) {
                std::cout << STD_TRACE_VAR(IN_CLOSE_WRITE) << std::endl;
            }
            if ( event->mask & IN_CLOSE_NOWRITE ) {
                std::cout << STD_TRACE_VAR(IN_CLOSE_NOWRITE) << std::endl;
            }
            if ( event->mask & IN_CLOSE ) {
                std::cout << STD_TRACE_VAR(IN_CLOSE) << std::endl;
            }
            if ( event->mask & IN_OPEN ) {
                std::cout << STD_TRACE_VAR(IN_OPEN) << std::endl;
            }
            if ( event->mask & IN_MOVED_FROM ) {
                std::cout << STD_TRACE_VAR(IN_MOVED_FROM) << std::endl;
            }
            if ( event->mask & IN_MOVED_TO ) {
                std::cout << STD_TRACE_VAR(IN_MOVED_TO) << std::endl;
            }
            if ( event->mask & IN_MOVE ) {
                std::cout << STD_TRACE_VAR(IN_MOVE) << std::endl;
            }
            if ( event->mask & IN_CREATE ) {
                std::cout << STD_TRACE_VAR(IN_CREATE) << std::endl;
            }
            if ( event->mask & IN_DELETE ) {
                std::cout << STD_TRACE_VAR(IN_DELETE) << std::endl;
            }
            if ( event->mask & IN_DELETE_SELF ) {
                std::cout << STD_TRACE_VAR(IN_DELETE_SELF) << std::endl;
            }
            if ( event->mask & IN_MOVE_SELF ) {
                std::cout << STD_TRACE_VAR(IN_MOVE_SELF) << std::endl;
            }
            if ( event->mask & IN_UNMOUNT ) {
                std::cout << STD_TRACE_VAR(IN_UNMOUNT) << std::endl;
            }
            if ( event->mask & IN_Q_OVERFLOW ) {
                std::cout << STD_TRACE_VAR(IN_Q_OVERFLOW) << std::endl;
            }
            if ( event->mask & IN_IGNORED ) {
                std::cout << STD_TRACE_VAR(IN_IGNORED) << std::endl;
            }
            if ( event->mask & IN_CLOSE ) {
                std::cout << STD_TRACE_VAR(IN_CLOSE) << std::endl;
            }
            if ( event->mask & IN_MOVE ) {
                std::cout << STD_TRACE_VAR(IN_MOVE) << std::endl;
            }
            if ( event->mask & IN_ONLYDIR ) {
                std::cout << STD_TRACE_VAR(IN_ONLYDIR) << std::endl;
            }
            if ( event->mask & IN_DONT_FOLLOW ) {
                std::cout << STD_TRACE_VAR(IN_DONT_FOLLOW) << std::endl;
            }
            if ( event->mask & IN_EXCL_UNLINK ) {
                std::cout << STD_TRACE_VAR(IN_EXCL_UNLINK) << std::endl;
            }
            if ( event->mask & IN_MASK_ADD ) {
                std::cout << STD_TRACE_VAR(IN_MASK_ADD) << std::endl;
            }
            if ( event->mask & IN_ISDIR ) {
                std::cout << STD_TRACE_VAR(IN_ISDIR) << std::endl;
            }
            if ( event->mask & IN_ONESHOT ) {
                std::cout << STD_TRACE_VAR(IN_ONESHOT) << std::endl;
            }
            else {
                std::cout << "Unknown event" << std::endl;
            }
        }

        i += EVENT_SIZE + event->len;
    }

    ::inotify_rm_watch( fd, wd );
    ::close( fd );
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
