/**
 * \file  Stl.h
 * \brief STL all headers
 *
 * Copy from https://github.com/skynowa/xLib/blob/master/Include/xLib/Core/Stl.h
 */


#pragma once

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if (__cplusplus >= 201103L)	// xLANG_CPP98
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>	// TODO: use only <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

// C++11
#include <array>
#include <chrono>
#include <codecvt>
#include <forward_list>
#include <initializer_list>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

// C++11 - MT / IPC
#include <thread>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <future>

#if (__cplusplus >= 201402L)	// xLANG_CPP14
#include <shared_mutex>
#endif

#if (__cplusplus >= 201703L)	// xLANG_CPP17
#include <any>
#include <optional>
#include <variant>
#include <string_view>
#include <charconv>
#include <filesystem>
// TODO: #include <execution>
#endif
