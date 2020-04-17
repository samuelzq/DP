// 凸多边形三角划分
//
// 问题描述
//
// 给定一个具有N(N <= 50)个顶点(从1到N编号)的凸多边形，每个顶点的权值已知。问如
// 何把这个凸多边形划分成N - 2个互不相交的三角形，使得这些三角形顶点的权值的乘积
// 之和最小。
//
// 输入
// 第一行为顶点数N，第二行为N个顶点（从1到N）的权值。
//
// 输出
// 乘积之和的最小值。题目保证结果在int范围内。
//
// 输入样例
// 5
// 1 6 4 2 1
// 5
// 121 122 123 245 231
//
// 输出样例
// 34
// 12214884

#include <iostream>
#include <cstdio>

using namespace std;
#define min(x, y) ((x) < (y) ? (x) : (y))

const int maxn = 0xAC;
int dp[maxn][maxn];
int v[maxn];

int main()
{
	int i, l, j, k, n;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> v[i];
		for (j = 0; j < n; j++)
			dp[i][j] = 0;
	}

	for (l = 2; l < n; l++) {
		for (i = 0; i < n && i + l < n; i++) {
			j = i + l;
			dp[i][j] = 0x1fffffff;
			for (k = i + 1; k < j; k++)
				dp[i][j] = min(dp[i][j],
							   dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
