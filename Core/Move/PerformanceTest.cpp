/**
 * \file  PerformanceTest.cpp
 * \brief
 *
 * https://pastebin.com/4Sa57VxB
 * https://www.youtube.com/watch?v=Z2_bXoqXgHg
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULE_5_OPTION_LOG  0
#define RULE_5_OPTION_COPY 1
#define RULE_5_OPTION_MOVE 1

#include <Idioms/Rule3Copy.h>
#include <Idioms/Rule3Move.h>
#include <Idioms/Rule5.h>
//--------------------------------------------------------------------------------------------------
template <typename T>
void
test()
{
	std::vector<T> vec;
	vec.emplace_back("k;jzxdxfjndfajk;bvmkl;adklm;dkl;m");
	vec.emplace_back("pzSJD'kfsngv;adojgn;aojngear;on");
	vec.emplace_back(";pksaMfkojnsg;'lkeng'eaoignea'oig");
	vec.emplace_back("ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc");
	vec.emplace_back("sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg");
	vec.emplace_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	vec.emplace_back("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
	vec.emplace_back("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	vec.emplace_back("dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
	vec.emplace_back("cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
	vec.emplace_back("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
	vec.emplace_back("vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd");
	vec.emplace_back("asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa");
	vec.emplace_back("gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf");
	vec.emplace_back("gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver");
	vec.emplace_back("k;jzxdxfjndfajk;bvmkl;adklm;dkl;m");
	vec.emplace_back("pzSJD'kfsngv;adojgn;aojngear;on");
	vec.emplace_back(";pksaMfkojnsg;'lkeng'eaoignea'oig");
	vec.emplace_back("ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc");
	vec.emplace_back("sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg");
	vec.emplace_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	vec.emplace_back("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
	vec.emplace_back("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	vec.emplace_back("dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
	vec.emplace_back("cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
	vec.emplace_back("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
	vec.emplace_back("vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd");
	vec.emplace_back("asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa");
	vec.emplace_back("gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf");
	vec.emplace_back("gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver");
	vec.emplace_back("k;jzxdxfjndfajk;bvmkl;adklm;dkl;m");
	vec.emplace_back("pzSJD'kfsngv;adojgn;aojngear;on");
	vec.emplace_back(";pksaMfkojnsg;'lkeng'eaoignea'oig");
	vec.emplace_back("ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc");
	vec.emplace_back("sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg");
	vec.emplace_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	vec.emplace_back("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
	vec.emplace_back("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	vec.emplace_back("dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
	vec.emplace_back("cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
	vec.emplace_back("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
	vec.emplace_back("vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd");
	vec.emplace_back("asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa");
	vec.emplace_back("gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf");
	vec.emplace_back("gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver");
	vec.emplace_back("k;jzxdxfjndfajk;bvmkl;adklm;dkl;m");
	vec.emplace_back("pzSJD'kfsngv;adojgn;aojngear;on");
	vec.emplace_back(";pksaMfkojnsg;'lkeng'eaoignea'oig");
	vec.emplace_back("ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc");
	vec.emplace_back("sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg");
	vec.emplace_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	vec.emplace_back("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
	vec.emplace_back("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	vec.emplace_back("dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
	vec.emplace_back("cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
	vec.emplace_back("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
	vec.emplace_back("vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd");
	vec.emplace_back("asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa");
	vec.emplace_back("gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf");
	vec.emplace_back("gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver");

	std::uint64_t operationsCount {};

	const auto timeStart = std::chrono::high_resolution_clock::now();

	for ( ; ; ) {
		const auto timeNow = std::chrono::high_resolution_clock::now();
		const auto diffSec = std::chrono::duration_cast<std::chrono::seconds>(timeNow - timeStart).count();

		if (diffSec >= 60) {
			break;
		}

		auto tmpVec = vec;

	#if 0
		while ( !tmpVec.empty() ) {
			auto it = tmpVec.cbegin();
			tmpVec.erase(it);
		}
	#endif

		++ operationsCount;
	}

	const std::string labelCopy =
	#if RULE_5_OPTION_COPY
		"Copy";
	#else
		"";
	#endif

	const std::string labelMove =
	#if RULE_5_OPTION_MOVE
		"Move";
	#else
		"";
	#endif

	std::cout
		<< "[" << labelCopy << " / " << labelMove << "] "
		<< STD_TRACE_VAR(operationsCount) << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	::test<Rule3Copy>();
	::test<Rule3Move>();
	::test<Rule5>();

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Copy - count: 7641408
Move - count: 16027970

#endif
