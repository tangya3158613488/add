#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
namespace TY
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* citerator;
		iterator Begin()
		{
			return _start;
		}
		iterator End()
		{
			return _finish;
		}
		citerator cBegin() const 
		{
			return _start;
		}
		citerator cEnd() const 
		{
			return _finish;
		}
		size_t Size() const
		{
			return _finish - _start;
		}
		size_t Capacity() const
		{
			return _endofstorage - _start;
		}
		//构造函数
		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//拷贝构造函数
		Vector(const Vector<T>& v)
		{
			_start = new T[v.Capacity()];
			iterator it = Begin();
			citerator vit = v.cBegin();
			while (vit != v.cEnd())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endofstorage = _start + v.Capacity();
		}
		Vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}
		//赋值重载hansh
		Vector<T>& operator=(const Vector<T>& v)
		{
			this->Swap(v);
			return *this;
		}
		//析构函数
		~Vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		template<class Inputiterator>
		Vector(Inputiterator first, Inputiterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}
		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);
		}
		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				//增容
				size_t size = Size();
				T*tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size; ++i)
					{
						tmp[i] = _start[i];//把原空间中的数据拷贝到新开的空间中
					}
				}
				delete[] _start;
				_start = tmp;
				_finish = _start + size;
				_endofstorage = _start + n;
			}
		}
		void Resize(size_t n,const T& value = T())
		{
			//如果n小于当前的Size()，则数据个数缩小到n
			if (n <= Size())
			{
				_finish = _start + n;
				return;
			}
			//如果n大于容量，增容
			if (n > Capacity())
			{
				Reserve(n);
			}
			//将Size()扩大到n
			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
	
		void PushBack(const T& x)
		{
			Insert(End(), x);
		}
		void PopBack()
		{
			iterator it = End();
			--it;
			Erase(it);
		}
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		iterator Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			
			//如果空间不够要增容
			if (_finish == _endofstorage)
			{
				size_t posindex = pos - _start;
				size_t size = Size();
				//如果是第一次插入数据，就要先把容量定为1，后面在有数据的情况下扩容就二倍增加
				size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newCapacity);
				pos = _start + posindex;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator Erase(iterator pos)
		{
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}
	private:
		iterator _start;//数据存放的开始位置
		iterator _finish;//数据存放结束位置的下一个位置
		iterator _endofstorage;//容量的最后一个位置
	};
}
//使用const迭代器进行遍历打印
void PrintVector(const TY::Vector<int>& v)
{
	TY::Vector<int>::citerator it = v.cBegin();
	while (it != v.cEnd())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void TestVector1()
{
	TY::Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.PushBack(5);
	TY::Vector<int> v2(4,10);
	TY::Vector<int> v3(v1);
	TY::Vector<string> strv;
	strv.PushBack("1111");
	strv.PushBack("2222");
	strv.PushBack("3333");
	strv.PushBack("aaaa");
	strv.PushBack("bbbb");
	//使用迭代器进行遍历
	TY::Vector<int>::iterator it1 = v1.Begin();
	while (it1 != v1.End())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	TY::Vector<int>::iterator it2 = v2.Begin();
	while (it2 != v2.End())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
	for (size_t i = 0; i < v3.Size(); ++i)
	{
		cout << v3[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < strv.Size(); ++i)
	{
		cout << strv[i] << " ";
	}
	cout << endl;
	
	
	//使用迭代器进行修改
	it1 = v1.Begin();
	while (it1 != v1.End())
	{
		*it1 *= 2;
		++it1;
	}
	PrintVector(v1);
	v3.PopBack();
	v3.PopBack();
	PrintVector(v3);
}
void TestVector2()
{
	int a[] = { 12, 23, 34, 15, 29, 30 };
	TY::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	v.Reserve(100);
	v.Resize(5);
	cout << v.Capacity() << endl;
	cout << v.Size() << endl;//6
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	
}
int main()
{
	TestVector2();
	return 0;
}