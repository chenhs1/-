// p331-7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//用回溯法生成{1,2,3,4}的所有排列

#include <iostream>
#include <vector>
using namespace std;
//打印结果
void printSolution(const vector<int> &v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

//构造递归函数，放第i个位置的数
void fun(vector<int> &v, vector<int> &f, int i)
{
	int n = v.size();
	for (int j = 1; j <= n; ++j)
	{
		//如果数j没有出现过，则第i个位置放j
		if (!f[j - 1])
		{
			f[j - 1] = 1;
			v[i] = j;
			//如果数全部放完，则打印结果
			if (i == n - 1)
			{
				printSolution(v);
			}
			else
			{
				fun(v, f, i + 1);
			}
			//回溯
			f[j - 1] = 0;
		}
	}
}

int main()
{
	cout << "输入n的值：";
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << "输入有误！" << endl;
		exit(1);
	}
	//记录全排列
	vector<int> v(n, 0);
	//f[i]记录i+1是否出现过
	vector<int> f(n, 0);
	fun(v, f, 0);
	return 0;
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
