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

    int fd = inotify_init();

    if ( fd < 0 ) {
        perror( "inotify_init" );
    }

    int wd = inotify_add_watch(fd, "./test.txt", IN_ALL_EVENTS);
    STD_TEST(wd > 0);

    int length = read(fd, buffer, BUF_LEN);
    STD_TEST(length >= 0)
    std::cout << STD_TRACE_VAR(length) << std::endl;

    int i = 0;

    while ( i < length ) {
        struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];
        std::cout << STD_TRACE_VAR(event->name) << std::endl;
        std::cout << STD_TRACE_VAR(event->len) << std::endl;

        if ( event->len ) {
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
            else {
                std::cout << STD_TRACE_VAR(event->name) << std::endl;
            }
        }

        i += EVENT_SIZE + event->len;
    }

    ( void ) inotify_rm_watch( fd, wd );
    ( void ) close( fd );

    exit( 0 );
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
