#define _CRT_SECURE_NO_WARNINGS 1
//СQ��ƽ���ϸ�����2 *n���㣬��Щ��n������A���ϣ�n������B���ϣ�����������A���Ϻ�B�����и�ѡ��һ���㣬�����п��������������̾���Ϊ���� ?
//����ľ���ָ����ŷ�Ͼ��룬���ڵ�(x1, y1), (x2, y2)���ǵ�ŷʽ����Ϊ :
//����������
//��һ������һ������n, ����A���Ϻ�B�����ڵĵ������Ϊn��
//������n�У�ÿһ��2����x��y, ����A�����ڵĵ������
//������n�У�ÿһ��2����x��y, ����B�����ڵĵ������
//1<n<100000
//1 �� x, y��10 ^ 9
//�������:
//����ÿ�����ݣ����һ���𰸴�����̾��룬�������3λС����

//#include<iostream>
//#include<cstdio>
//#include<fstream>
//#include<cstring>
//#include<algorithm>
//#include<cstdlib>
//#include<cmath>
//using namespace std;
//
//typedef long long ll;
//
//struct Point{
//	int x;
//	int y;
//	int c;
//	ll d;
//
//	bool operator <(const Point other) const{
//		return d < other.d;
//	}
//};
//
//inline int read()
//{
//	char ch = getchar(); int x = 0, f = 1;
//	while (ch < '0' || ch > '9') 
//	{
//		if (ch == '-') f = -1;
//		ch = getchar();
//	} 
//	while ('0' <= ch && ch <= '9') 
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	} 
//	return x * f;
//}
//
//const int maxn = 1e5 + 5;
//
//int t, n;
//int windowSize = 1;
//Point p[2 * maxn];
//
//inline ll dist(Point p, Point q)
//{
//	return (ll)(p.x - q.x) * (p.x - q.x) + (ll)(p.y - q.y) * (p.y - q.y);
//}
//
//
//int main()
//{
//	//scanf("%d", &t);
//
//	t = read();
//
//	while (t--)
//	{
//		//scanf("%d", &n);
//
//		n = read();
//
//		int tot = n + n;
//		for (int i = 1; i <= tot; ++i)
//		{
//			//scanf("%d%d", &p[i].x, &p[i].y);
//
//			p[i].x = read(); p[i].y = read();
//
//			if (i <= n)
//				p[i].c = 0;
//			else
//				p[i].c = 1;
//
//			p[i].d = (ll)p[i].x * p[i].x + (ll)p[i].y * p[i].y;
//		}
//
//		sort(p + 1, p + tot + 1);
//
//		ll ans = -1, curDist;
//
//		for (int i = 1; i < tot; ++i)
//		{
//			if (p[i].c != p[i + 1].c)
//			{
//				curDist = dist(p[i], p[i + 1]);
//				if (ans == -1 || curDist < ans)ans = curDist;
//			}
//		}
//
//		printf("%.3f\n", sqrt(ans));
//	}
//
//	return 0;
//}

#include<iostream>
using namespace std;

//class Base
//{
//public:
//	Base(int x = 0)
//	{
//		cout << x;
//	}
//};
//class Derived :public Base
//{
//public:
//	Derived(int X = 0)
//	{
//		cout << X;
//	}
//private:
//	Base value;
//};
//int main()
//{
//	Derived d(1);
//	return 0;
//}

//int main()
//{
//	int count = 0;
//	for (int x = 0, y = 0; !x && y <= 3; y++)
//	{
//		int c = !x&&y;
//		cout << !x << "&&" << y << "=" << c << endl;
//		count++;
//	}
//	cout << count;
//}