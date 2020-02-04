#include <iostream>
#include <mutex>
using namespace std;

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{
		//如果是一个空指针对象，引用计数赋值为0
		if (ptr == nullptr)
			*_pRefCount = 0;
	}
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{
		if (_ptr)
			AddRefCount();
	}
	//sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			//先释放管理的旧资源
			Release();
			//然后共享管理新对象的资源，并增加引用计数
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			if (_ptr)
				AddRefCount();
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int UseCount()
	{
		return *_pRefCount;
	}
	T* Get()
	{
		return _ptr;
	}

	~SharedPtr()
	{
		Release();
	}

	int AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
		return *_pRefCount;
	}
	int SubRefCount()
	{
		_pMutex->lock();
		--(*_pRefCount);
		_pMutex->unlock();
		return *_pRefCount;
	}
private:
	void Release()
	{
		//如果引用计数减到0，则释放资源
		if (_ptr && SubRefCount() == 0)
		{
			delete _ptr;
			delete _pRefCount;
		}
	}
	int* _pRefCount;//引用计数指针
	T* _ptr;//指向管理资源的指针
	mutex* _pMutex;//互斥锁
};