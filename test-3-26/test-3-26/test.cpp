#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	const double P = 3.14159;
	int n = 5;
	vector<int> v{ 1, 2, 3, 4, 5 };
	double sum = v[0] * v[0];
	for (size_t k = 2; k < n; k += 2)
	{
		sum += v[k] * v[k] - v[k - 1] * v[k - 1];
	}
	double ret = P*sum;
	cout << ret << endl;
	return 0;
}