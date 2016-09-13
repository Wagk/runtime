#ifndef CONCURRENT_JOB_H
#define CONCURRENT_JOB_H

namespace concurrent
{
	
	class job
	{
	public:

		void exec();

	protected:

		virtual void desc() = 0;
		
	};

} //namespace concurrent

#endif