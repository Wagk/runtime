#include <iostream>

#include "concurrent/kernel.h"

/*
	Each thread has a worker object
*/

int main(int argc, char* argv[])
{
	sandcastle::concurrent::kernel::get().init();
	sandcastle::concurrent::kernel::get().launch_main_worker();
}