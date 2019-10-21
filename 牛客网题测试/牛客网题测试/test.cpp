#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n = 3;
//	vector<int> v;
//	v.push_back(-1);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(5);
//	v.push_back(6);
//	v.push_back(7);
//	int cur = 0;
//	int next = 1;
//	int res = 0, res1 = 0;
//	while (next < n)
//	{
//		if (abs(v[cur] - v[next]) == 1 && next < n)
//		{
//			res += v[cur] + v[next];
//			++cur;
//			next = cur + 1;
//			if (res1 < res)
//				res1 = res;
//			else
//				res = 0;
//		}
//		else
//		{
//			++cur;
//			++next;
//		}
//	}
//	cout << res1 << endl;
//	return 0;
//}
//#include<stdio.h>
//#define N 3
//int x[N];
//int count = 0;
//void dump() {
//	int i = 0;
//	for (i = 0; i < N; i++) {
//		printf("%d", x[i]);
//	}
//	printf("\n");
//}
//
//void swap(int a, int b) {
//	int t = x[a];
//	x[a] = x[b];
//	x[b] = t;
//}
//
//void run(int n)
//{
//	int i;
//	if (N - 1 == n)
//	{
//		dump();
//		count++;
//		return;
//	}
//	for (i = n; i < N; i++)
//	{
//		swap(n, i);
//		run(n + 1);
//		swap(n, i);
//	}
//}
//
//int main()
//{
//	int i;
//	for (i = 0; i < N; i++) 
//	{
//		x[i] = i + 1;	
//	}
//	run(0);
//	printf("* Total: %d\n", count);
//	
//}


#include <iostream> 
using namespace std;
int main(void)
{
	int i=1;
	long j=2;
	double x=0;
	long long a=3;
	long double b=4;
	cout<<sizeof(i)<<endl;
	cout<<sizeof(j)<<endl;
	cout<<sizeof(x)<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;
	
	return 0;
}