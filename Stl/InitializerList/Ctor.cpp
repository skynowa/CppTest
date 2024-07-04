/**
 * \file  Ctor.cpp
 * \brief
 *
 * \see
 * \todo  Leak (core dumped)
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct Data
{
    std::size_t                         num;
    std::initializer_list<const char *> json_ptrs;
    bool                                expected;
};

const std::vector<Data> datas
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

        for (const auto &it_json_ptr : it_data.json_ptrs) {
            std::cout << STD_TRACE_VAR(it_json_ptr) << std::endl;
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

datas.size(): 3

it_data.num: 1
it_data.json_ptrs.size(): 2

it_json_ptr: ��X �
it_json_ptr: ��X �

it_data.num: 2
it_data.json_ptrs.size(): 2

it_json_ptr: ��X �
/home/skynowa/Projects/Scripts/Shell/cpp_compile.sh: line 33: 41719 Segmentation fault      (core dumped) "$OUTPUT"

#endif
