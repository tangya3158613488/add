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
		//�����һ����ָ��������ü�����ֵΪ0
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
			//���ͷŹ���ľ���Դ
			Release();
			//Ȼ��������¶������Դ�����������ü���
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
		//������ü�������0�����ͷ���Դ
		if (_ptr && SubRefCount() == 0)
		{
			delete _ptr;
			delete _pRefCount;
		}
	}
	int* _pRefCount;//���ü���ָ��
	T* _ptr;//ָ�������Դ��ָ��
	mutex* _pMutex;//������
};