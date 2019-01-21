#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//template<class T>
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.21, d = 2.43;
//	Swap(a, b);
//	Swap(c, d);
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	cout << d << endl;
//	return 0;
//}

template<class T>
class Vector
{
public:
	//初始化Vector
	Vector(size_t capacity = 10)
		:_array(new T[capacity])
		, _size(0)
		, _capacity(0)
	{}
	//析构函数
	~Vector()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = _capacity = 0;
		}
	}
	void PushBack(const T& data)
	{
		if (_array[_size] <= 10)
		{
			_array[_size++] = data;
		}
	}
	void PopBack()
	{
		--_size;
	}
	size_t size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _array[pos];
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};
int main()
{
	Vector<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PopBack();
	s1.operator[](1);
	cout << s1[1] << endl;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	return 0;
}