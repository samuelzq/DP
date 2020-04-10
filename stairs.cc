#include <iostream>
#include <cstdio>

using namespace std;

const int max_lin = 200 + 0xAC;
int dp[max_lin] = {0, };

int f1(int n)
{
	if (n == 1 || n == 2) {
		dp[n] = n;
	} else {
		if (dp[n - 1] == 0)
			dp[n - 1] = f1(n - 1);
		if (dp[n - 2] == 0)
			dp[n - 2] = f1(n - 2);
		dp[n] = dp[n - 1] + dp[n - 2];
	}
	return dp[n];
}

int f2(int n)
{
	int a, b, k;

	if (n == 1 || n == 2)
		return n;

	a = 1;
	b = 2;
	for (int i = 3; i <= n; i++) {
		k = a + b;
		a = b;
		b = k;
	}
	return k;
}

int main()
{
	int n, ans;
#ifdef FILE_INOUT
	freopen("input.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
	cin >> n;
	ans = f1(n);
	cout << ans << endl;
#ifdef FILE_INOUT
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}