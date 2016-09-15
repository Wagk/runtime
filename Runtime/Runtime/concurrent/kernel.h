#ifndef CONCURRENT_KERNEL_H
#define CONCURRENT_KERNEL_H

/*
	- spawns workers
	- informs them of the queues of other workers to steal from
*/

#include <thread>
#include <vector>
#include "deque.h"

namespace concurrent
{

	class kernel
	{
	public:

		void init();
		void shutdown();

	private:
		
		struct workerinfo
		{
			deque _queue; //thread local queue
			std::vector<deque*> _steal_queues;//pointers to other queues
			bool _kill;		//kill flag
			bool _graphics;	//affinities
		};

		void worker(workerinfo* info);

		unsigned int _numthreads;

		workerinfo _maininfo;
		std::vector<std::pair<workerinfo, std::thread>> _threadpool;

	};

} //namespace concurrent

#endif