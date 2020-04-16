// 我们有一个连续的序列，每个序列上面都是一个数字c[i]，每次我们都能够消灭一个连
// 续的回文子序列，消灭之后左右会合并，成为一个新序列，问最少需要多少次才能够把
// 整个序列消灭掉。回文就是从左到有从右到左读到的序列都是一样的。
// 例如一开始的序列是1 4 4 2 3 2 1，那么我们最少需要2次，先消灭掉4 4 ， 然后再消
// 灭调1 2 3 2 1.

#include <iostream>

using namespace std;
#define min(x, y) ((x) < (y) ? (x) : (y))

const int max_n = 1000;

int dp[max_n][max_n] = {{0, 0},};
int a[max_n];

int main()
{
	int i, j, g, n;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> a[i];
		for (j = i + 1; j < n; j++)
			dp[i][j] = j - i + 1;
		dp[i][i] = 1;
	}

	for (g = 1; g < n; g++) {
		for (i = 0; i + g < n; i++) {
			j = i + g;
			if (a[i] == a[i + 1]) //case2
				dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
			else //case1
				dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);

			for (int k = i + 2; k <= j; k++) { // case3
				if (a[i] == a[k])
					dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j - 1]);
			}
		}
	}

	cout << dp[0][n - 1] << endl;
	return 0;
}