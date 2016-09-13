#ifndef CONCURRENT_KERNEL_H
#define CONCURRENT_KERNEL_H

/*
	- spawns workers
	- informs them of the queues of other workers to steal from
*/

#include <thread>
#include <vector>

namespace concurrent
{

	class kernel
	{
	public:

		void init();
		void shutdown();

	private:

		void worker();

	};

} //namespace concurrent

#endif