/**
 * \file  ProgramOptions.cpp
 * \brief boost::program_options
 *
 * https://theboostcpplibraries.com/boost.program_options
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <boost/program_options.hpp>
//-------------------------------------------------------------------------------------------------
void
toCout(const std::vector<std::string> &v)
{
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<std::string>{std::cout, "\n"});
}
//-------------------------------------------------------------------------------------------------
int main(int argc, const char *argv[])
{
	namespace po = boost::program_options;

	try {
		int age {};

		po::options_description desc{"Options"};
		desc.add_options()
			("help,h", "Help screen")
			("pi",     po::value<float>()->implicit_value(3.14f), "Pi")
			("age",    po::value<int>(&age), "Age")
			("phone",  po::value<std::vector<std::string>>()
							->multitoken()
							->zero_tokens()
							->composing(),
							"Phone")
			("unreg",  "Unrecognized options");

		po::command_line_parser parser{argc, argv};
		parser
			.options(desc)
			.allow_unregistered().style(
				po::command_line_style::default_style |
				po::command_line_style::allow_slash_for_short);
		po::parsed_options parsed_options = parser.run();

		po::variables_map vm;
		std::cout << STD_TRACE_VAR(vm.size()) << std::endl;

		po::store(parsed_options, vm);
		po::notify(vm);

		if      (vm.count("help")) {
			std::cout << desc << std::endl;
		}
		else if (vm.count("age")) {
			std::cout << "Age: " << age << std::endl;
		}
		else if (vm.count("phone")) {
			::toCout(vm["phone"].as<std::vector<std::string>>());
		}
		else if (vm.count("unreg")) {
			::toCout(collect_unrecognized(parsed_options.options, po::exclude_positional));
		}
		else if (vm.count("pi")) {
			std::cout << "Pi: " << vm["pi"].as<float>() << std::endl;
		}
	}
	catch (const po::error &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (const std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown exception" << std::endl;
	}

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

vm.size(): 0

#endif
