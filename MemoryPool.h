// MemoryPool.h
// Copyright 2018/11/7 Robin.Rowe@CinePaint.org
// License open source MIT

#ifndef MemoryPool_h
#define MemoryPool_h

#include <string>
#include <stdio.h>

namespace IPC {

class MemoryPool
{protected:
	void* p;
	bool isAllocator;
	std::string name;
	void Reset()
	{	p = 0;
		isAllocator = false;
		name.clear();
	}
	void Init(const char* name,bool isAllocator)
	{	Reset();
		this->name = name;
		this->isAllocator = isAllocator;
	}
	virtual void PrintError(const char* msg)
	{	perror(msg);
	}
	virtual bool Close()
	{	return false;
	}
	virtual void* Create(size_t size)
	{	return 0;
	}
	virtual void* Open(size_t size)
	{	return 0;
	}
public:
	MemoryPool()
	:	p(0)
	{}
	virtual ~MemoryPool()
	{	Close();
	}
	void* Allocate(size_t size)
	{	return isAllocator? Create(size):Open(size);
	}
	void Deallocate(void* p)
	{	if(this->p == p)
		{	Close();
	}	}
};

}

#endif
