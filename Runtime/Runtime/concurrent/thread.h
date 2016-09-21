#ifndef CONCURRENT_THREAD_H
#define CONCURRENT_THREAD_H

#include <vector>

#include "worker.h"
#include "deque.h"

namespace sandcastle 
{
	namespace concurrent
	{

		namespace this_thread
		{
			extern thread_local worker this_worker;
		}

	} //namespace concurrent
}

#endif