/**
 * \file  Reverse.cpp
 * \brief Enum in reverse order
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    enum RoomAttributeType
    {
    	RoomAType    = 8,
    	RoomClass    = 7,
    	RoomConfig   = 6,
    	RoomLocation = 5,
    	RoomAmenity  = 4,
    	RoomPolicy   = 3,
    	RoomView     = 2,
    	RoomBed      = 1,
    	Unknown      = 0,
    	XXX
    };

    std::cout << STD_TRACE_VAR(RoomAttributeType::XXX) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

RoomAttributeType::XXX: 1

#endif
