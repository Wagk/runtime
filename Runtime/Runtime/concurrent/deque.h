#ifndef CONCURRENT_DEQUE_H
#define CONCURRENT_DEQUE_H

#include <mutex>
#include <deque>

#include "job.h"

/*
	TODO:
		- Make this lockfree
*/

namespace sandcastle {
	namespace concurrent
	{

		class deque
		{
		public:

			deque();
			deque(const deque& rhs);

			bool empty() const;

			void push(job* task);
			job* pop();
			job* steal();

		private:

			mutable std::mutex _lock;
			std::deque<job*> _queue;

		};

	} 
}


#endif