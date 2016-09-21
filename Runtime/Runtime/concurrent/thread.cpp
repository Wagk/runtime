#include "thread.h"

namespace sandcastle
{
	namespace concurrent
	{
		namespace this_thread
		{
			thread_local worker this_worker;
		}
	} //namespace concurrent
}