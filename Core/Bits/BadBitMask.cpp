/**
 * \file  BadBitMask.cpp
 * \brief Overflow bit mask
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main()
{
    // Bit operation for "0"
    {
        std::size_t i{};

        i |= 32;

        std::cout << STD_TRACE_VAR(i) << std::endl;
    }

    // Overflow bit mask
    {
        std::cout << std::endl;

        for (uint64_t i = 0; i < 70; ++ i) {
            const uint64_t gds_id = i;

            const auto mask_bad = (1    << (gds_id - 1));
            const auto mask_ok  = (1ULL << (gds_id - 1ULL));

            std::cout
                << gds_id << " - "
                << "Bad mask: " << mask_bad << ", "
                << "OK mask: "  << mask_ok << std::endl;
        }
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

i: 32

0 - Bad mask: -2147483648, OK mask: 9223372036854775808
1 - Bad mask: 1, OK mask: 1
2 - Bad mask: 2, OK mask: 2
3 - Bad mask: 4, OK mask: 4
4 - Bad mask: 8, OK mask: 8
5 - Bad mask: 16, OK mask: 16
6 - Bad mask: 32, OK mask: 32
7 - Bad mask: 64, OK mask: 64
8 - Bad mask: 128, OK mask: 128
9 - Bad mask: 256, OK mask: 256
10 - Bad mask: 512, OK mask: 512
11 - Bad mask: 1024, OK mask: 1024
12 - Bad mask: 2048, OK mask: 2048
13 - Bad mask: 4096, OK mask: 4096
14 - Bad mask: 8192, OK mask: 8192
15 - Bad mask: 16384, OK mask: 16384
16 - Bad mask: 32768, OK mask: 32768
17 - Bad mask: 65536, OK mask: 65536
18 - Bad mask: 131072, OK mask: 131072
19 - Bad mask: 262144, OK mask: 262144
20 - Bad mask: 524288, OK mask: 524288
21 - Bad mask: 1048576, OK mask: 1048576
22 - Bad mask: 2097152, OK mask: 2097152
23 - Bad mask: 4194304, OK mask: 4194304
24 - Bad mask: 8388608, OK mask: 8388608
25 - Bad mask: 16777216, OK mask: 16777216
26 - Bad mask: 33554432, OK mask: 33554432
27 - Bad mask: 67108864, OK mask: 67108864
28 - Bad mask: 134217728, OK mask: 134217728
29 - Bad mask: 268435456, OK mask: 268435456
30 - Bad mask: 536870912, OK mask: 536870912
31 - Bad mask: 1073741824, OK mask: 1073741824
32 - Bad mask: -2147483648, OK mask: 2147483648
33 - Bad mask: 1, OK mask: 4294967296
34 - Bad mask: 2, OK mask: 8589934592
35 - Bad mask: 4, OK mask: 17179869184
36 - Bad mask: 8, OK mask: 34359738368
37 - Bad mask: 16, OK mask: 68719476736
38 - Bad mask: 32, OK mask: 137438953472
39 - Bad mask: 64, OK mask: 274877906944
40 - Bad mask: 128, OK mask: 549755813888
41 - Bad mask: 256, OK mask: 1099511627776
42 - Bad mask: 512, OK mask: 2199023255552
43 - Bad mask: 1024, OK mask: 4398046511104
44 - Bad mask: 2048, OK mask: 8796093022208
45 - Bad mask: 4096, OK mask: 17592186044416
46 - Bad mask: 8192, OK mask: 35184372088832
47 - Bad mask: 16384, OK mask: 70368744177664
48 - Bad mask: 32768, OK mask: 140737488355328
49 - Bad mask: 65536, OK mask: 281474976710656
50 - Bad mask: 131072, OK mask: 562949953421312
51 - Bad mask: 262144, OK mask: 1125899906842624
52 - Bad mask: 524288, OK mask: 2251799813685248
53 - Bad mask: 1048576, OK mask: 4503599627370496
54 - Bad mask: 2097152, OK mask: 9007199254740992
55 - Bad mask: 4194304, OK mask: 18014398509481984
56 - Bad mask: 8388608, OK mask: 36028797018963968
57 - Bad mask: 16777216, OK mask: 72057594037927936
58 - Bad mask: 33554432, OK mask: 144115188075855872
59 - Bad mask: 67108864, OK mask: 288230376151711744
60 - Bad mask: 134217728, OK mask: 576460752303423488
61 - Bad mask: 268435456, OK mask: 1152921504606846976
62 - Bad mask: 536870912, OK mask: 2305843009213693952
63 - Bad mask: 1073741824, OK mask: 4611686018427387904
64 - Bad mask: -2147483648, OK mask: 9223372036854775808
65 - Bad mask: 1, OK mask: 1
66 - Bad mask: 2, OK mask: 2
67 - Bad mask: 4, OK mask: 4
68 - Bad mask: 8, OK mask: 8
69 - Bad mask: 16, OK mask: 16

#endif
