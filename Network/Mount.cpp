/**
 * \file
 * \brief
 *
 * \todo
 */


#include <StdTest.h>

#include <sys/mount.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
  string host = "192.168.12.200";
  string src = "\\\\homes";
  string dst = "~/tmp/jail";
  string fstype = "cifs";

  string all_string = "unc=" + src + ",ip=" + host + ",username=skynowa,password=1978abccbA";

  printf("src: %s\n", src.c_str());

  if( -1 == mount(src.c_str(), dst.c_str(), fstype.c_str(), MS_MGC_VAL | MS_SILENT , all_string.c_str()))
  {
      printf("mount failed with error: %s\n",strerror(errno));
  }
  else
      printf("mount success!\n");

  if( umount2(dst.c_str(), MNT_FORCE) < 0 )
  {
      printf("unmount failed with error: %s\n",strerror(errno));
  }
  else
      printf("unmount success!\n");


  return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
