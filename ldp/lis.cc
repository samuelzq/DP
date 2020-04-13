#include <iostream>

#include <cstdio>
#include <cstring>

using namespace std;
#define max(x, y) ((x) > (y) ? (x) : (y))

const int max_lin = 200 + 0xAC;
int dp[max_lin] = {0, };
int w[max_lin] = {0, };

int dp1(int n)
{
	int ans = 0;
	ans = dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (w[i] > w[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	return ans = dp[n - 1];
}

int dp2(int n)
{
	int ans = 0;
	dp[0] = w[0];
	for (int i = 1; i < n; i++) {
		if (w[i] > dp[ans]) {
			ans += 1;
			dp[ans] = w[i];
		} else {
			int h, t, m;
			h = 0;
			t = ans;
			while (h < t) {
				m = (h + t) / 2;
				if (w[i] > dp[m])
					h = m + 1;
				else
					t = m;
			}
			dp[h] = w[i];
		}
	}
	return ans + 1;
}

int main()
{
	int n, i, ans;
#ifdef FILE_INOUT
	freopen("input.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif

	cin >> n;

	for (i = 0; i < n; i++)
		cin >> w[i];

	ans = dp2(n);
	cout << ans << endl;
#ifdef FILE_INOUT
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}