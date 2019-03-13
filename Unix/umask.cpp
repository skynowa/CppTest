/**
 * \file  main.cpp
 * \brief https://support.sas.com/documentation/onlinedoc/sasc/doc/lr2/umask.htm
 */


#include <StdStream.h>
#include <StdTest.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
#if 0
	mode_t old_mask = umask( 011 );

	open( ... );

	umask( old_mask );
#endif

	mode_t oldMask {};
	mode_t newMask {};

	// Get old mask, temporarily setting the mask to 0
	oldMask = ::umask((mode_t) 0);

	// Print old mask. Octal values are used by mask
	printf("Old mask = %o\n", (int) oldMask);

	// Make sure group read permission is allowed
	if (oldMask & S_IRGRP) {
		printf("Changing group read permission from MASKED to UNMASKED.\n");
		oldMask = (oldMask ^ S_IRGRP);
	}

	// Make sure group write and execute permission is not allowed.
	newMask = (oldMask|S_IWGRP|S_IXGRP);

	::umask(newMask);                            // Update mask
	printf("New mask = %o\n\n", (int) newMask);    // Print new mask

	printf("The file mode creation mask now specifies:\n\n");
	printf("	Group read permission      UNMASKED\n");
	printf("	Group write permission     MASKED\n");
	printf("	Group execute permission   MASKED\n");

	// std::cout << TRACE_VAR("") << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Old mask = 2
New mask = 32

The file mode creation mask now specifies:

     Group read permission      UNMASKED
     Group write permission     MASKED
     Group execute permission   MASKED


#endif

