// 数字金字塔
//
// 本程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。
// 每一步可以走到左下方的点也可以到达右下方的点。
//
//         7
//       3   8
//     8   1   0
//   2   7   4   4
// 4   5   2   6   5 

#include <iostream>
#include <cstdio>

using namespace std;
#define max(x, y) ((x) > (y) ? (x) : (y))

const int max_layer = 200 + 0xAC;
int dp[max_layer][max_layer] = {0, };
int w[max_layer][max_layer] = {0, };


int main()
{
	int n, i, j, ans;
#ifdef FILE_INOUT
	freopen("input.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif

	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++)
			cin >> w[i][j];
	}
	dp[0][0] = w[0][0];
	for (i = 1; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + w[i][j];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] + w[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + w[i][j];
		}
	}
	ans = dp[n - 1][0];
	for (i = 1; i < n; i++)
		ans = (ans > dp[n - 1][i]) ? ans : dp[n - 1][i];
	cout << ans << endl;
#ifdef FILE_INOUT
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}