#include "job.h"

namespace sandcastle
{
	namespace concurrent
	{

		void job::run()
		{
			func();
		}

	} //namespace concurrent
}