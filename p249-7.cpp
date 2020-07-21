// p249-7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*有n个人，各自都知道一个不同的谣言。他们想要通过电子消息来与彼此分享这些“新闻”。
要想保证每一个人都知道所有的谣言，那么他们所需要发送的电子消息数最少是多少？
假设每一次发送，发送者都将他或她所知道的所有谣言都发送了，并且每个消息只能有一个接收者。
答：所需的最少的消息数目为2n-2
*/

#include <iostream>

using namespace std;

const int maxnum = 100;
const int maxint = 999999;



void initation(int dist[maxnum][maxnum], int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = maxint;
		}
	}
}
void Dijkstra(int n, int v, int dist[maxnum][maxnum], int *prev, int c[maxnum][maxnum])
{
	bool s[maxnum];
	for (int i = 1; i <= n; ++i)
	{
		dist[v][i] = c[v][i];
		s[i] = 0;
		if (dist[v][i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v][v] = 0;
	s[v] = 1;

	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
	for (int i = 2; i <= n; ++i)
	{
		int tmp = maxint;
		int u = v;
		// 找出当前未使用的点j的dist[j]最小值
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[v][j] < tmp)
			{
				u = j;
				tmp = dist[v][j];
			}
		s[u] = 1;

					 // 更新dist
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && c[u][j] < maxint)
			{
				int newdist = dist[v][u] + c[u][j];
				if (newdist < dist[v][j])
				{
					dist[v][j] = newdist;
					prev[j] = u;
				}
			}
	}
}

void searchPath(int *prev, int v, int u)
{
	int que[maxnum];
	int tot = 1;
	que[tot] = u;
	tot++;
	int tmp = prev[u];
	while (tmp != v)
	{
		que[tot] = tmp;
		tot++;
		tmp = prev[tmp];
	}
	que[tot] = v;
	for (int i = tot; i >= 1; --i)
		if (i != 1)
			cout << que[i] << " -> ";
		else
			cout << que[i] << endl;
}

void YuanDian(int dist[maxnum][maxnum], int n, int m[maxnum]) {
	for (int i = 1; i <= n; i++) {
		m[i] = dist[i][1];
		for (int j = 1; j <= n; j++) {
			if (m[i] < dist[i][j] && i != j) {
				m[i] = dist[i][j];
			}
		}
	}
	int min = m[1];
	int a = 0;
	for (int k = 1; k <= n; k++) {
		if (min > m[k]) {
			min = m[k];
			a = k;
		}
	}
	cout << "应从" << a << "开始" << "时间最短为" << min << endl;
}

int main()
{
	// 各数组都从下标1开始
	int dist[maxnum][maxnum];
	int prev[maxnum];
	int c[maxnum][maxnum];
	int n, line;
	int m[maxnum];
	// 输入结点数
	cin >> n;
	// 输入路径数
	cin >> line;
	int p, q, len;

							// 初始化c[][]为maxint
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			c[i][j] = maxint;

	for (int i = 1; i <= line; ++i)
	{
		cin >> p >> q >> len;
		c[p][q] = len;
	}


	initation(dist, n);
	for (int i = 1; i <= n; i++) {
		Dijkstra(n, i, dist, prev, c);
	}

	YuanDian(dist, n, m);
	system("pause");
	//searchPath(prev, 1, k);
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
