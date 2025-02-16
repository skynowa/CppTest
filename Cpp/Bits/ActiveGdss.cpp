/**
 * \file  ActiveGdss.cpp
 * \brief Active bits
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const std::vector<unsigned long long> gds_masks
    {
        // 137439084544,
        // 35184372088832,
        // 140737488355328
        2305847407394422784
    };

    for (auto it_gds_mask : gds_masks) {
    	auto gds_mask = it_gds_mask;

        // Vector to store active gds_ids
        std::vector<int> active_gds_ids;

        // Bit position starts at 1
        int position = 1;

        // Iterate through all bits of it_gds_mask
        while (gds_mask > 0) {
            // Check if the least significant bit is set
            if (gds_mask & 1) {
                active_gds_ids.push_back(position);
            }

            // Shift right to process the next bit
            gds_mask >>= 1;

            ++ position;
        }

        std::cout << STD_TRACE_VAR2(it_gds_mask, active_gds_ids) << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

it_gds_mask: 137439084544,    active_gds_ids: std::vector (size=2): {18,38}
it_gds_mask: 35184372088832,  active_gds_ids: std::vector (size=1): {46}
it_gds_mask: 140737488355328, active_gds_ids: std::vector (size=1): {48}

#endif
