#ifndef CONCURRENT_DEQUE_H
#define CONCURRENT_DEQUE_H

#include <mutex>
#include <deque>

#include "job.h"

/*
	TODO:
		- Make this lockfree
*/

namespace concurrent
{

	class deque
	{
	public:

		void push(job* task);
		job* pop();
		job* steal();

	private:

		mutable std::mutex _lock;
		std::deque<job*> _queue;

	};

} //namespace concurrent


#endif