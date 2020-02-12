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
	//��1
	void Set(size_t which)
	{
		if (which > _count)
			return;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		_bit[index] |= (1 << pos);
	}
	//��0
	void reSet(size_t which)
	{
		if (which > _count)
			return;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		_bit[index] &= ~(1 << pos);
	}
	//���λͼ��which�Ƿ�Ϊ1
	bool Test(size_t which)
	{
		if (which > _count)
			return false;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		return _bit[index] % (1 << pos);
	}
	//��ȡ����λ���ܸ���
	size_t Size()const
	{
		return _count;
	}
private:
	vector<int> _bit;
	size_t _count;
};