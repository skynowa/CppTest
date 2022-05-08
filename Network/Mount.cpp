/**
 * \file  Mount.cpp
 * \brief
 */


#include <StdTest/StdTest.h>

#include <sys/mount.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int iRv {};

    const string host   = "192.168.12.200";
    const string src    = "\\\\homes";
    const string dst    = "~/tmp/jail";
    const string fstype = "cifs";

    string all_string = "unc=" + src + ",ip=" + host + ",username=skynowa,password=1978abccbA";
    printf("src: %s\n", src.c_str());

    iRv = mount(src.c_str(), dst.c_str(), fstype.c_str(), MS_MGC_VAL | MS_SILENT , all_string.c_str());
    if (iRv == -1) {
        printf("mount failed with error: %s\n",strerror(errno));
        return 1;
    }

    printf("mount success!\n");

    iRv = umount2(dst.c_str(), MNT_FORCE);
    if (iRv  < 0) {
        printf("unmount failed with error: %s\n",strerror(errno));
        return 1;
    }

    printf("unmount success!\n");

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
