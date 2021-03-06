#ifndef _Lock_H
#define _Lock_H

#include <pthread.h>
#include "Uncopiable.h"

class MyLock : Uncopiable
{
public:

	MyLock()
	{
		pthread_mutex_init(&m_mutex, nullptr);
	}

	~MyLock()
	{
		pthread_mutex_destroy(&m_mutex);
	}

	void Lock()
	{
		pthread_mutex_lock(&m_mutex);
	}

	void UnLock()
	{
		pthread_mutex_unlock(&m_mutex);
	}

private:
	pthread_mutex_t m_mutex;
};


class AutoLock
{
public:

	explicit AutoLock(MyLock &rLock)
	{
		m_pLock = &rLock;
		m_pLock->Lock();
	}

	~AutoLock()
	{
		m_pLock->UnLock();
	}

private:
	MyLock *m_pLock;
	AutoLock();
};


#endif // _Lock_H

