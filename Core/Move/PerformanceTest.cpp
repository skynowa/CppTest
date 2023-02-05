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

#define RULEOF5_OPTION_COPY 1
#define RULEOF5_OPTION_MOVE 1

#include <Idioms/Rule5.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const std::vector<Rule5> vec =
	{
		"k;jzxdxfjndfajk;bvmkl;adklm;dkl;m",
		"pzSJD'kfsngv;adojgn;aojngear;on",
		";pksaMfkojnsg;'lkeng'eaoignea'oig",
		"ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc",
		"sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
		"dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd",
		"cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
		"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
		"vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd",
		"asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa",
		"gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf",
		"gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver",
		"k;jzxdxfjndfajk;bvmkl;adklm;dkl;m",
		"pzSJD'kfsngv;adojgn;aojngear;on",
		";pksaMfkojnsg;'lkeng'eaoignea'oig",
		"ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc",
		"sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
		"dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd",
		"cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
		"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
		"vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd",
		"asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa",
		"gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf",
		"gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver",
		"k;jzxdxfjndfajk;bvmkl;adklm;dkl;m",
		"pzSJD'kfsngv;adojgn;aojngear;on",
		";pksaMfkojnsg;'lkeng'eaoignea'oig",
		"ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc",
		"sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
		"dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd",
		"cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
		"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
		"vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd",
		"asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa",
		"gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf",
		"gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver",
		"k;jzxdxfjndfajk;bvmkl;adklm;dkl;m",
		"pzSJD'kfsngv;adojgn;aojngear;on",
		";pksaMfkojnsg;'lkeng'eaoignea'oig",
		"ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc",
		"sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
		"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
		"dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd",
		"cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
		"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
		"vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd",
		"asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa",
		"gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf",
		"gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver"
	};

	std::uint64_t count {};

	const auto start_time = std::chrono::high_resolution_clock::now();

	while (std::chrono::duration_cast<
		std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count() < 60)
	{
		auto tmp_vec = vec;

		while ( !tmp_vec.empty() ) {
			auto it = tmp_vec.cbegin();
			tmp_vec.erase(it);
		}

		++ count;
	}

	const std::string labelCopy =
	#if RULEOF5_OPTION_COPY
		"Copy";
	#else
		"";
	#endif

	const std::string labelMove =
	#if RULEOF5_OPTION_MOVE
		"Move";
	#else
		"";
	#endif

	std::cout
		<< "[" << labelCopy << " / " << labelMove << "] "
		<< STD_TRACE_VAR(count) << std::endl;

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Copy - count: 7641408
Move - count: 16027970

#endif
