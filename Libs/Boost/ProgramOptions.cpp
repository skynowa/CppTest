/**
 * \file  ProgramOptions.cpp
 * \brief Boost.ProgramOptions
 *
 * \todo
 *
 * https://theboostcpplibraries.com/boost.program_options
 */


#include <boost/program_options.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace po = boost::program_options;
//-------------------------------------------------------------------------------------------------
void to_cout(const std::vector<std::string> &v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>{std::cout, "\n"});
}
//-------------------------------------------------------------------------------------------------
int main(int argc, const char *argv[])
{
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
		parser.options(desc).allow_unregistered().style(
			po::command_line_style::default_style |
			po::command_line_style::allow_slash_for_short);
		po::parsed_options parsed_options = parser.run();

		po::variables_map vm;
		po::store(parsed_options, vm);
		po::notify(vm);

		if      (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("age"))
			std::cout << "Age: " << age << '\n';
		else if (vm.count("phone"))
			to_cout(vm["phone"].as<std::vector<std::string>>());
		else if (vm.count("unreg"))
			to_cout(collect_unrecognized(parsed_options.options, po::exclude_positional));
		else if (vm.count("pi"))
			std::cout << "Pi: " << vm["pi"].as<float>() << '\n';
	}
	catch (const po::error &ex) {
		std::cerr << ex.what() << '\n';
	}
}
//-------------------------------------------------------------------------------------------------
