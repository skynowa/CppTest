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
namespace my
{

class shared_mutex
{
public:
///\name ctors, dtor
///\{
	shared_mutex() = default;
   ~shared_mutex() = default;
///\}

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

private:
	static constexpr unsigned write_entered_ = 1U << (sizeof(unsigned) * CHAR_BIT - 1);
	static constexpr unsigned n_readers_     = ~write_entered_;

	std::mutex              mut_;
	std::condition_variable gate1_;
	std::condition_variable gate2_;
	unsigned                state_ {};
};	///<

} // namespace my
//-------------------------------------------------------------------------------------------------
