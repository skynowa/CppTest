/**
 * \file  SharedMutex_cpp14.h
 * \brief Shared / Unique Ownership Mutexes and Locks
 *
 * \see   https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2406.html#shared_mutex_imp
 *
 * \todo
 */


#pragma once
//-------------------------------------------------------------------------------------------------
#include <mutex>
#include <condition_variable>
#include <limits.h>	// CHAR_BIT
//-------------------------------------------------------------------------------------------------
class my_shared_mutex
{
	std::mutex              mut_;
	std::condition_variable gate1_;
	std::condition_variable gate2_;
	unsigned                state_;

	static const unsigned write_entered_ = 1U << (sizeof(unsigned)*CHAR_BIT - 1);
	static const unsigned n_readers_     = ~write_entered_;

public:
	my_shared_mutex() : state_(0) {}

///\name Exclusive ownership
///\{
	void lock();
	bool try_lock();
	bool timed_lock(std::chrono::nanoseconds rel_time);
	void unlock();
///\}

///\name Shared ownership
///\{
	void lock_shared();
	bool try_lock_shared();
	bool timed_lock_shared(std::chrono::nanoseconds rel_time);
	void unlock_shared();
///\}
};
//-------------------------------------------------------------------------------------------------
