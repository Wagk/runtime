#include "deque.h"

namespace concurrent
{
	void deque::push(job* task)
	{
		if (task == nullptr) return;

		std::lock_guard<std::mutex> lock(_lock);

		_queue.push_front(task);
	}

	job * deque::pop()
	{
		std::lock_guard<std::mutex> lock(_lock);

		if (_queue.empty() == true)
			return nullptr;

		job* task = _queue.front();
		_queue.pop_front();

		return task;
	}

	job * deque::steal()
	{
		std::lock_guard<std::mutex> lock(_lock);

		if (_queue.empty() == true)
			return nullptr;

		job* task = _queue.back();
		_queue.pop_back();

		return task;
	}

} //namespace concurrent