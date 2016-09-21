#include "worker.h"

#include <cassert>

namespace sandcastle
{
	namespace concurrent
	{

		void worker::init(const worker_data& info)
		{
			assert(info._work);
			assert(info._stop);

			_data = info;
		}

		void worker::run()
		{
			while (_data._stop->load() == false)
			{
				if (_data._work->empty())
				{
					//perform work stealing
				}
				else
				{
					job* task = _data._work->pop();

					task->run();
				}
			}
		}

		void worker::submit_job(job* task)
		{
			if (task == nullptr)
				return;

			_data._work->push(task);
		}

	} //namespace concurrent
}