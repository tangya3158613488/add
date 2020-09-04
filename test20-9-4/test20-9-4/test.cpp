#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
#define M 3
#define N 4

//输入一个二维数组，实现每行每列都是升序排序
void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void BubbleSorti(vector<vector<int>>& vv,int i)
{
	int end = N;
	while (end > 0)
	{
		int flag = 0;
		for (int j = 0; j < N - 1; j++)
		{
			if (vv[i][j] > vv[i][j + 1])
			{
				Swap(&vv[i][j], &vv[i][j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
void BubbleSortj(vector<vector<int>>& vv, int j)
{
	int end = M;
	while (end > 0)
	{
		int flag = 0;
		for (int i = 0; i < M-1; i++)
		{
			if (vv[i][j] > vv[i+1][j])
			{
				Swap(&vv[i][j], &vv[i + 1][j]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
int main()
{	
	vector<vector<int>> vv;
	int data;
	for (int i = 0; i < M; i++)
	{
		vector<int> v;
		for (int j = 0; j < N; j++)
		{
			cin >> data;
			v.push_back(data);
		}
		vv.push_back(v);
	}
	//每行进行升序排序
	
	for (int i = 0; i < M; i++)
	{
		BubbleSorti(vv, i);
	}
	//每列进行升序排序
	for (int j = 0; j < N; j++)
	{
		BubbleSortj(vv, j);
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}