#ifndef CONCURRENT_JOB_H
#define CONCURRENT_JOB_H

namespace sandcastle {
	namespace concurrent
	{

		class job
		{
		public:

			void run();

		protected:

			virtual void func() = 0;

		};

	}
} 

#endif