#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int> &v, int left, int right, int number)
{
	int mid = left + ((right - left) >> 1);
	if (number == v[mid])
		return mid;
	else if (number < v[mid])
		return BinarySearch(v, left, mid - 1, number);
	else
		return BinarySearch(v, mid + 1, right, number);
	if (left > right)
		return -1;
}
int main()
{
	int n;
	cin >> n;
	int data;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		v.push_back(data);
	}
	int number;
	cin >> number;
	int index = BinarySearch(v, 0, n - 1, number);
	cout << index << endl;
	return 0;
}
