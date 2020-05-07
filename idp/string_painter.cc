/* String painter
 *
 * Time Limit: 5000/2000 MS (Java/Others)
 * Memory Limit:32768/32768 K (Java/Others)
 * Total Submission(s): 4691    Accepted Submission(s): 2208
 *
 *
 * Problem Description
 *
 * There are two strings A and B with equal length. Both strings are made up of
 * lowercase letters. Now you have a powerful string painter. With the help of
 * the painter, you can change a segment of characters of a string to any other
 * character you want. That is, after using the painter, the segment is made up
 * of only one kind of character. Now your task is to change A to B using string
 * painter. What’s the minimum number of operations?
 *
 * Input
 *
 * Input contains multiple cases. Each case consists of two lines:
 * The first line contains string A.
 * The second line contains string B.
 * The length of both strings will not be greater than 100.
 *
 * Output
 *
 * A single line contains one integer representing the answer.
 *
 * Sample Input
 *
 * zzzzzfzzzzz
 * abcdefedcba
 *
 * abababababab
 * cdcdcdcdcdcd
 *
 * Sample Output
 * 6
 * 7
 */

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
#define min(x, y)  ((x) < (y) ? (x) : (y))

typedef long long ll;
const int maxn = 105;
const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;

int dp[maxn][maxn];
int ans[maxn];

int main()
{
	int i, j, k;
	string s1, s2;
#ifdef FILE_INOUT
	freopen("input.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
    while (cin >> s1 >> s2)	{
		int n = s1.length();
		memset(dp, 0, sizeof(dp) / sizeof(int));

		for (i = 0; i < n; i++) {
			for(j = i; j < n; j++)
				dp[i][j] = j - i + 1;
		}

		for (j = 0; j < n; j++) {
			for (i = j; i >= 0; i--) {
				for (k = i + 1; k <= j; k++)	{
					/* whether s2[i] could be painted with the left side */
					if (s2[i] == s2[k])
						dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
				}
			}
		}

		for (i = 1; i <= n; i++) {
			ans[i] = dp[0][i];
			if (s1[i] == s2[i]) {
				ans[i] = min(ans[i], ans[i - 1]);
			} else {
				for (j = 1; j < i; j++)
					ans[i] = min(ans[i], ans[j] + dp[j + 1][i]);
			}
		}
		cout << ans[n - 1] << '\n';
	}

#ifdef FILE_INOUT
	fclose(stdin);
	fclose(stdout);
#endif
    return 0;
}