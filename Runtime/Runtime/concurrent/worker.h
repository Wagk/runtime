#ifndef CONCURRENT_WORKER_H
#define CONCURRENT_WORKER_H

#include <atomic>
#include <vector>

#include "job.h"
#include "deque.h"

namespace sandcastle
{
	namespace concurrent
	{
		struct worker_data
		{
			deque* _work;
			std::vector<deque*> _steal;
			std::atomic<bool>* _stop;
		};

		class worker
		{
		public:

			void init(const worker_data& info);
			void run();

			void submit_job(job* job);

		private:

			worker_data _data;

		};

	} //namespace concurrent
}

#endif