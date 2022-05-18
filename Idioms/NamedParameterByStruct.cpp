/**
 * \file  NamedParameterByStruct.cpp
 * \brief Solve order of the parameters problem
 *
 * Pass params as sruct
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// Named Params - No
void draw(size_t xPosition, size_t yPosition, size_t width, size_t height, bool drawingNow)
{
	std::cout
		<< "Named Params - No:\n"
		<< STD_TRACE_VAR5(xPosition, yPosition, width, height, drawingNow)
		<< "\n" << std::endl;
}
//--------------------------------------------------------------------------------------------------
// Named Params - Yes
struct Params
{
    int  xPosition;
    int  yPosition;
    int  width;
    int  height;
    bool drawingNow;
};

void draw(const Params &params)
{
	std::cout
		<< "Named Params - Yes:\n"
		<< STD_TRACE_VAR5(params.xPosition, params.yPosition, params.width, params.height,
			params.drawingNow)
		<< "\n" << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const auto p1 {20};
	const auto p2 {50};
	const auto p3 {100};
	const auto p4 {5};
	const auto p5 {true};

	// Named Params - No
	{
		::draw(p1, p2, p3, p4, p5);
	}

	// Named Params - Yes
	{
		const Params params
		{
			.xPosition  = p1,
			.yPosition  = p2,
			.width      = p3,
			.height     = p4,
			.drawingNow = p5
		};

		::draw(params);
	}

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Named Params - No:
xPosition: 20, yPosition: 50, width: 100, height: 5, drawingNow: 1

Named Params - Yes:
params.xPosition: 20, params.yPosition: 50, params.width: 100, params.height: 5, params.drawingNow: 1

#endif
