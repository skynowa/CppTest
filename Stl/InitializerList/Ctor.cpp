/**
 * \file  Ctor.cpp
 * \brief
 *
 * \see
 * \todo  Leak
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct Data
{
    std::size_t num;
    std::initializer_list<std::string> json_ptrs;
    bool expected;
};

const vector<Data> datas
{
    {1, {"/object", "/invalid_node0"}, true},
    {2, {"/array", "/invalid_node1"}, true},
    {3, {"/object/invalid_node2", "/invalid_node2"}, false}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << STD_TRACE_VAR(datas.size()) << std::endl;
    std::cout << std::endl;

    for (const Data &it_data : datas) {
        std::cout << STD_TRACE_VAR(it_data.num) << std::endl;
        std::cout << STD_TRACE_VAR(it_data.json_ptrs.size()) << std::endl;
        std::cout << std::endl;

        for (const string &it_json_ptr : it_data.json_ptrs) {
            cout << STD_TRACE_VAR(it_json_ptr) << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT



#endif
