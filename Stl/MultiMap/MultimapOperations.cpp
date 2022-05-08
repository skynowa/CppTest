/**
 * \file  MultimapOperations.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main()
{
    std::multimap <int, int> mm;

    // insert elements in random order
    mm.insert(std::pair<int, int>(1, 40));
    mm.insert(std::pair<int, int>(2, 30));
    mm.insert(std::pair<int, int>(3, 60));
    mm.insert(std::pair<int, int>(4, 20));
    mm.insert(std::pair<int, int>(5, 50));
    mm.insert(std::pair<int, int>(6, 50));
    mm.insert(std::pair<int, int>(6, 10));

    // printing std::multimap mm
    std::cout << "\nThe std::multimap mm is : \n";
    std::cout << "\tKEY\tELEMENT\n";

    for (auto itr = mm.cbegin(); itr != mm.cend(); ++ itr) {
        std::cout
            << '\t' << itr->first
            << '\t' << itr->second << '\n';
    }

    std::cout << std::endl;

    // assigning the elements from mm to gquiz2
    std::multimap<int, int> gquiz2(mm.cbegin(), mm.cend());

    // print all elements of the std::multimap gquiz2
    std::cout << "\nThe std::multimap gquiz2 after assign from mm is : \n";
    std::cout << "\tKEY\tELEMENT\n";

    for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++ itr) {
        std::cout
            << '\t' << itr->first
            << '\t' << itr->second << '\n';
    }

    std::cout << std::endl;

    // remove all elements up to element with value 30 in gquiz2
    std::cout << "\ngquiz2 after removal of elements less than key=3 : \n";
    std::cout << "\tKEY\tELEMENT\n";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));

    for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
    {
        std::cout
            << '\t' << itr->first
            << '\t' << itr->second << '\n';
    }

    // remove all elements with key = 4
    int num = gquiz2.erase(4);
    std::cout << "\ngquiz2.erase(4) : ";
    std::cout << num << " removed \n" ;
    std::cout << "\tKEY\tELEMENT\n";

    for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        std::cout
            << '\t' << itr->first
            << '\t' << itr->second << '\n';
    }

    std::cout << std::endl;

    // lower bound and upper bound for std::multimap mm key = 5
    std::cout << "mm.lower_bound(5) : " << "\tKEY = ";
    std::cout << mm.lower_bound(5)->first << '\t';
    std::cout << "\tELEMENT = " << mm.lower_bound(5)->second << std::endl;

    std::cout << "mm.upper_bound(5) : " << "\tKEY = ";
    std::cout << mm.upper_bound(5)->first << '\t';
    std::cout << "\tELEMENT = " << mm.upper_bound(5)->second << std::endl;

    return 0;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

The std::multimap mm is :
	KEY	ELEMENT
	1	40
	2	30
	3	60
	4	20
	5	50
	6	50
	6	10


The std::multimap gquiz2 after assign from mm is :
	KEY	ELEMENT
	1	40
	2	30
	3	60
	4	20
	5	50
	6	50
	6	10


gquiz2 after removal of elements less than key=3 :
	KEY	ELEMENT
	3	60
	4	20
	5	50
	6	50
	6	10

gquiz2.erase(4) : 1 removed
	KEY	ELEMENT
	3	60
	5	50
	6	50
	6	10

mm.lower_bound(5) : 	KEY = 5		ELEMENT = 50
mm.upper_bound(5) : 	KEY = 6		ELEMENT = 50

#endif
