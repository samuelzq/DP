// 整数划分
//
// 时间限制：1000 ms  |  内存限制：65535 KB
//
// 难度：3
//
// 描述
//
// 暑假来了，hrdv又要留学校在参加ACM集训了，集训的生活非常Happy（ps：你懂得），
// 可是他最近遇到了一个难题，让他百思不得其解，他非常郁闷。亲爱的你能帮帮他吗？
//
// 问题是我们经常见到的整数划分，给出两个整数 n , m ,要求在 n 中加入m - 1 个乘
// 号，将n分成m段，求出这m段的最大乘积
//
// 输入
//
// 第一行是一个整数T，表示有T组测试数据
// 接下来T行，每行有两个正整数 n，m ( 1 <= n < 10^19, 0 < m <= n的位数)；
//
// 输出
//
// 输出每组测试样例结果为一个整数占一行
//
// 样例输入
//
// 2
// 111 2
// 1111 2
//
// 样例输出
//
// 11
// 121

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define max(x, y) ((x) > (y) ? (x) : (y))

const int maxn = 0xAC;
long long dp[maxn][maxn];
long long num[maxn][maxn];
long long ans[maxn];

int main()
{
	int t, i, j, k;

	cin >> t;
	for (i = 0; i < t; i++)	{
		string s;
		int m;
		cin >> s >> m;
		memset(dp, 0, sizeof(dp));

		int l = s.length();
		for (int i = 1; i <= l; i++) {
			num[i][i] = s[i - 1] - '0';
			for (j = i + 1; j <= l; j++)
				num[i][j] = num[i][j - 1] * 10 + s[j - 1] - '0';
		}
		for (int i = 1; i <= l; i++)
			dp[i][0] = num[1][i];

		for (j = 1; j < m; j++) {
			for (int i = j + 1; i <= l; i++) {
				for (k = j; k < i; k++)
					dp[i][j] = max(dp[i][j], dp[k][j - 1] * num[k + 1][i]);
			}
		}
		ans[i] = dp[l][m - 1];
	}

	for (i = 0; i < t; i++)
		cout << ans[i] << '\n';
	cout << endl;
	return 0;
}