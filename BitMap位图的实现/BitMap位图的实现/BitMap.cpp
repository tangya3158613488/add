#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class BitMap
{
public:
	BitMap(size_t count)
		: _bit((count >> 5) + 1)
		, _count(count)
	{}
	//置1
	void Set(size_t which)
	{
		if (which > _count)
			return;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		_bit[index] |= (1 << pos);
	}
	//置0
	void reSet(size_t which)
	{
		if (which > _count)
			return;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		_bit[index] &= ~(1 << pos);
	}
	//检测位图中which是否为1
	bool Test(size_t which)
	{
		if (which > _count)
			return false;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		return _bit[index] % (1 << pos);
	}
	//获取比特位的总个数
	size_t Size()const
	{
		return _count;
	}
private:
	vector<int> _bit;
	size_t _count;
};