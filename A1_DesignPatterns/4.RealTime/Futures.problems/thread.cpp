////////////////////////////////////////////////////////////
//
//      Thread class
//
////////////////////////////////////////////////////////////

#include "thread.h"
#include "thread_impl.h"

thread::thread() 
	: pTarget(0), pThread_impl(0) 
{
	pThread_impl = new thread_impl(this);
}

thread::thread(runnable& target) 
	: pTarget(&target), pThread_impl(0) 
{
	pThread_impl = new thread_impl(this);
}

thread::~thread()
{
    delete pThread_impl;
}

void thread::start()
{
   pThread_impl->start();
}

HANDLE thread::getId()
{
    return pThread_impl->getHandle();
}

int thread::run()
{
	int result = 0;
	if(pTarget != 0) result = pTarget->run();
	return result;
}

void thread::join()
{
   pThread_impl->join();
}

