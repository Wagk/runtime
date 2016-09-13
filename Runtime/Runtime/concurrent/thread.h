#ifndef CONCURRENT_THREAD_H
#define CONCURRENT_THREAD_H

#include "deque.h"

namespace concurrent
{

	struct thread_globals
	{
		deque _queue;
	};

	namespace this_thread
	{
		extern thread_local thread_globals global;
	} 

} //namespace concurrent

#endif