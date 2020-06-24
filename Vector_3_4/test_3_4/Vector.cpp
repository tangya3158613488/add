#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
#include<algorithm>
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
		//���캯��
		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//�������캯��
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
		//��ֵ���غ���
		Vector<T>& operator=(const Vector<T>& v)
		{
			this->Swap(v);
			return *this;
		}
		//��������
		~Vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		//����������
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
				//����
				size_t size = Size();
				T*tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size; ++i)
					{
						tmp[i] = _start[i];//��ԭ�ռ��е����ݿ������¿��Ŀռ���
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
			//���nС�ڵ�ǰ��Size()�������ݸ�����С��n
			if (n <= Size())
			{
				_finish = _start + n;
				return;
			}
			//���n��������������
			if (n > Capacity())
			{
				Reserve(n);
			}
			//��Size()����n
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
			
			//����ռ䲻��Ҫ����
			if (_finish == _endofstorage)
			{
				size_t posindex = pos - _start;
				size_t size = Size();
				//����ǵ�һ�β������ݣ���Ҫ�Ȱ�������Ϊ1�������������ݵ���������ݾͶ�������
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
		iterator _start;//���ݴ�ŵĿ�ʼλ��
		iterator _finish;//���ݴ�Ž���λ�õ���һ��λ��
		iterator _endofstorage;//���������һ��λ��
	};
}
//ʹ��const���������б�����ӡ
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
	//ʹ�õ��������б���
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
	
	
	//ʹ�õ����������޸�
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

void TestVector3()
{
	TY::Vector<int> first;
	TY::Vector<int> second(4, 100);
	TY::Vector<int> third(second.Begin(), second.End());
	TY::Vector<int> fourth(third);

	int myints[] = { 2, 5, 1, 18 };
	TY::Vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	cout << "The content of fifth are: ";
	for (TY::Vector<int>::iterator it = fifth.Begin(); it != fifth.End(); it++)
	{
		cout << ' ' << *it;
	}
	cout << endl;
}
void TestVector4()
{
	TY::Vector<int> foo;
	size_t sz = foo.Capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.PushBack(i);
		if (sz != foo.Capacity())
		{
			sz = foo.Capacity();
			cout << "Capacity changed: " << sz << endl;
		}
	}
	TY::Vector<int> bar;
	sz = bar.Capacity();
	bar.Reserve(100);
	cout << "making bar grow:\n";
	for (int i = 0; i < 100; i++)
	{
		bar.PushBack(i);
		if (sz != bar.Capacity())
		{
			sz = bar.Capacity();
			cout << "Capacity changed: " << sz << endl;
		}
	}
	TY::Vector<int> myvector;
	for (int i = 1; i < 10; i++)
	{
		myvector.PushBack(i);
	}
	myvector.Resize(5);
	myvector.Resize(8, 10);
	myvector.Resize(10);
	cout << "myvector contains: ";
	for (int i = 0; i < myvector.Size(); i++)
	{
		cout << ' ' << myvector[i];
	}
	cout << endl;
	cout << "myvector's capacity is " << myvector.Capacity() << endl;
}
void TestVector5()
{
	int a[] = { 1, 2, 3, 4 };
	TY::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	TY::Vector<int>::iterator pos = find(v.Begin(), v.End(), 3);
	//��posλ��֮ǰ����30
	v.Insert(pos, 30);
	TY::Vector<int>::iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.Begin(), v.End(), 3);
	//ɾ��posλ�õ�ֵ
	v.Erase(pos);
	it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	//TestVector2();
	//TestVector3();
	//TestVector4();
	TestVector5();
	return 0;
}