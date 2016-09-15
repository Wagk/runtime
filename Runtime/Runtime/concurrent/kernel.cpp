#include "kernel.h"
#include <thread>
#include <utility>

namespace concurrent
{

	void kernel::init()
	{
		_numthreads = std::thread::hardware_concurrency() - 1;

		_threadpool.resize(_numthreads);

		//main thread
		_maininfo._kill = false;
		_maininfo._graphics = true;
		
		for (auto& thread : _threadpool)
		{
			deque* queueptr = &thread.first._queue;
			_maininfo._steal_queues.push_back(queueptr);
		}

		//spawned threads
		for (auto& thread : _threadpool)
		{
			workerinfo& info = thread.first;

			info._steal_queues.reserve(_numthreads + 1);
			info._steal_queues.push_back(&_maininfo._queue);
			for (auto& elem : _threadpool)
			{
				if(&elem.first._queue != &thread.first._queue)
					info._steal_queues.push_back(&elem.first._queue);
			}

			info._kill = false;
			info._graphics = false;
		}

		for (auto& thread : _threadpool)
		{
			thread.second = std::move(std::thread(&thread.first));
		}

	}

	void kernel::shutdown()
	{
		for (auto& thread : _threadpool)
		{
			thread.first._kill = true;
		}

		for (auto& thread : _threadpool)
		{
			thread.second.join();
		}
	}

	void kernel::worker(workerinfo* info)
	{

		
	}

} //namespace concurrent