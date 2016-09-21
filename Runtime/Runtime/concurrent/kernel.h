#ifndef CONCURRENT_KERNEL_H
#define CONCURRENT_KERNEL_H

/*
	- spawns workers
	- informs them of the queues of other workers to steal from
*/

#include <thread>
#include <vector>
#include <atomic>

#include "deque.h"
#include "thread.h"
#include "worker.h"

namespace sandcastle
{
	namespace concurrent
	{

		class kernel
		{
		public:

			static kernel& get()
			{
				static kernel singleton;
				return singleton;
			}

			void init();
			void shutdown();

			void launch_main_worker();

		private:

			static void launch_worker(worker_data data);

			unsigned int _numthreads; //including main thread

			std::atomic<bool> _stop;

			worker_data _main_data;

			std::vector < std::thread > _threadpool;
			std::vector < deque > _queuepool;

		};

	} //namespace concurrent
}

#endif