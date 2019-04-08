#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "除0错误";
	}
	return (double)a / (double)b;
}
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	
	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete[] _ptr;
	}
private:
	T* _ptr;
};

int main()
{
	try
	{
		int* array = new int[10];
		SmartPtr<int> sp(array);
		
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	catch (...)
	{
	}
	return 0;
}

template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	
	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete[] _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
struct Date
{
	int _year;
	int _month;
	int _day;
};
int main()
{
	SmartPtr<int> sp1(new int(10));
	*sp1 = 10;
	cout << *sp1 << endl;
	SmartPtr<Date> sp(new Date);
	sp->_year = 2019;
	sp->_month = 4;
	sp->_day = 7;
	cout << sp->_year << "-" << sp->_month << "-" << sp->_day << endl;
}

namespace TY
{
	template<class T>
	class AutoPtr
	{
	public:
		AutoPtr(T* ptr)
			:_ptr(ptr)
		{}

		~AutoPtr()
		{
			cout << "delete:" << _ptr << endl;
			delete[] _ptr;
		}
		//一旦发生拷贝，就将ap中的资源转移到当前对象中，然后将ap与所管理的资源断开联系，即将ap中的资源清空
		AutoPtr(AutoPtr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}
		AutoPtr<T>& operator=(AutoPtr<T>& ap)
		{
			//检查是否自己给自己赋值
			if (this != &ap)
			{
				//释放当前对象中的资源
				if (_ptr)
					delete[] _ptr;
				//将ap中的资源转移到当前对象中
				_ptr = ap._ptr;
				ap._ptr = nullptr;
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
	private:
		T* _ptr;
	};
	struct Date
	{
		int _year;
		int _month;
		int _day;
	};
}
int main()
{
	TY::AutoPtr<TY::Date> ap(new TY::Date);
	TY::AutoPtr<TY::Date> copy(ap);
	ap->_year = 2019;
	return 0;
}

namespace TY
{
	template<class T>
	class UniquePtr
	{
	public:
		UniquePtr(T* ptr)
			:_ptr(ptr)
		{}

		~UniquePtr()
		{
			cout << "delete:" << _ptr << endl;
			delete[] _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		//C++98防拷贝的方式：只声明不实现+声明成私有
		UniquePtr(UniquePtr<T> const &);
		UniquePtr & operator=(UniquePtr<T> const &);
		//C++11防拷贝的方式：delete
		/*UniquePtr(UniquePtr<T> const &) = delete;
		UniquePtr & operator=(UniquePtr<T> const &) = delete;*/
	private:
		T* _ptr;
	};
}
int main()
{
	TY::UniquePtr<int> up(new int);
	TY::UniquePtr<int> copy(up);//报错，不可访问
	return 0;
}


#include<thread>
#include<mutex>
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _pcount(new int(1))
		, _pmutex(new mutex)
	{
		if (_ptr == nullptr)
			*_pcount = 0;
	}


	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pcount(sp._pcount)
		, _pmutex(sp._pmutex)
	{
		if (_ptr)
			AddCount();
	}

	//sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			Release();

			_ptr = sp._ptr;
			_pcount = sp._pcount;
			_pmutex = sp._pmutex;
			if (_ptr)
				AddCount();
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
		return *_pcount;
	}
	T* Get()
	{
		return _ptr;
	}
	int AddCount()
	{
		//加锁或使用加1的原子操作
		_pmutex->lock();
		++(*_pcount);
		_pmutex->unlock();
		return *_pcount;
	}

	int SubCount()
	{
		//加锁或使用减一的原子操作
		_pmutex->lock();
		--(*_pcount);
		_pmutex->unlock();
		return *_pcount;
	}
	void Release()
	{
		if (_ptr && SubCount() == 0)
		{
			delete _ptr;
			delete _pcount;
		}
	}

	~SharedPtr()
	{
		Release();
	}

private:
	T* _ptr;//指向管理资源的指针
	int* _pcount;//引用计数
	mutex* _pmutex;//互斥锁

};
struct AA
{
	int _a = 1;
	int _b = 1;
	int _c = 1;
};
void SharedPtrFunc(SharedPtr<AA>& sp, size_t n)
{
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		SharedPtr<AA> copy(sp);
		copy->_a++;
		copy->_b++;
		copy->_c++;
	}
}
线程安全问题是偶然出现性问题，当n大到一定程度时，就会出现线程安全问题
void Test()
{
	SharedPtr<AA> sp(new AA);
	cout << sp.Get() << endl;
	const size_t n = 1000000;
	thread t1(SharedPtrFunc, sp, n);
	thread t2(SharedPtrFunc, sp, n);
	t1.join();
	t2.join();
	cout << sp->_a << endl;
	cout << sp->_b << endl;
	cout << sp->_c << endl;


}
int main()
{
	/*SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp1.Get() << endl;
	cout << sp2.Get() << endl;

	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	cout << sp1.Get() << endl;
	cout << sp2.Get() << endl;
	cout << sp3.Get() << endl;

	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	cout << sp1.Get() << endl;
	cout << sp2.Get() << endl;
	cout << sp3.Get() << endl;*/
	Test();

	return 0;
}
#include<memory>
struct ListNode 
{
	int _data;  
	shared_ptr<ListNode> _prev;   
	shared_ptr<ListNode> _next;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

int main()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	return 0;
}
struct ListNode 
{
	int _data;   
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;

	~ListNode(){ cout << "~ListNode()" << endl; }
};

int main() 
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode); 
	cout << node1.use_count() << endl;   
	cout << node2.use_count() << endl;

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	return 0;
}

#include <thread>
#include <mutex>

// C++11的库中也有一个lock_guard，下面的LockGuard造轮子其实就是为了学习他的原理 
template<class Mutex> class LockGuard 
{
public:

	LockGuard(Mutex& mtx)
     :_mutex(mtx)
	{
		_mutex.lock();
    }

   ~LockGuard() 
   {
	   _mutex.unlock();
   }

	LockGuard(const LockGuard<Mutex>&) = delete;

private:  
	// 注意这里必须使用引用，否则锁的就不是一个互斥量对象    
	Mutex& _mutex;
};

	mutex mtx;
	static int n = 0;

	void Func()
	{
		for (size_t i = 0; i < 1000000; ++i)
		{
			LockGuard<mutex> lock(mtx);
			++n;
		}
	}

int main() 
{
	int begin = clock();
	thread  t1(Func);
	thread  t2(Func);

	t1.join();
	t2.join();

	int end = clock();

	cout << n << endl;
	cout << "cost time:" << end - begin << endl;
	return 0;
}


