#define _CRT_SECURE_NO_WARNINGS 1
//小Q在平面上给定了2 *n个点，这些点n个属于A集合，n个属于B集合，现在让你在A集合和B集合中各选择一个点，求所有可能中两个点的最短距离为多少 ?
//这里的距离指的是欧氏距离，对于点(x1, y1), (x2, y2)他们的欧式距离为 :
//输入描述：
//第一行输入一个整数n, 代表A集合和B集合内的点的数量为n。
//接下来n行，每一行2个数x和y, 代表A集合内的点的坐标
//接下来n行，每一行2个数x和y, 代表B集合内的点的坐标
//1<n<100000
//1 ≤ x, y≤10 ^ 9
//输出描述:
//对于每组数据，输出一个答案代表最短距离，结果保留3位小数。

#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef long long ll;

struct Point{
	int x;
	int y;
	int c;
	ll d;

	bool operator <(const Point other) const{
		return d < other.d;
	}
};

inline int read()
{
	char ch = getchar(); int x = 0, f = 1;
	while (ch < '0' || ch > '9') 
	{
		if (ch == '-') f = -1;
		ch = getchar();
	} 
	while ('0' <= ch && ch <= '9') 
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	} 
	return x * f;
}

const int maxn = 1e5 + 5;

int t, n;
int windowSize = 1;
Point p[2 * maxn];

inline ll dist(Point p, Point q)
{
	return (ll)(p.x - q.x) * (p.x - q.x) + (ll)(p.y - q.y) * (p.y - q.y);
}


int main()
{
	//scanf("%d", &t);

	t = read();

	while (t--)
	{
		//scanf("%d", &n);

		n = read();

		int tot = n + n;
		for (int i = 1; i <= tot; ++i)
		{
			//scanf("%d%d", &p[i].x, &p[i].y);

			p[i].x = read(); p[i].y = read();

			if (i <= n)
				p[i].c = 0;
			else
				p[i].c = 1;

			p[i].d = (ll)p[i].x * p[i].x + (ll)p[i].y * p[i].y;
		}

		sort(p + 1, p + tot + 1);

		ll ans = -1, curDist;

		for (int i = 1; i < tot; ++i)
		{
			if (p[i].c != p[i + 1].c)
			{
				curDist = dist(p[i], p[i + 1]);
				if (ans == -1 || curDist < ans)ans = curDist;
			}
		}

		printf("%.3f\n", sqrt(ans));
	}

	return 0;
}