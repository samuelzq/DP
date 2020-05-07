/**** Cake slicing
 *
 * Time Limit: 2000/1000 MS (Java/Others)
 * Memory Limit:32768/32768 K (Java/Others)
 * Total Submission(s): 283    Accepted Submission(s): 139
 *
 * Problem Description
 *
 * A rectangular cake with a grid of m*n unit squares on its top needs to be
 * sliced into pieces. Several cherries are scattered on the top of the cake
 * with at most one cherry on a unit square. The slicing should follow the
 * rules below:
 * 1.  each piece is rectangular or square;
 * 2.  each cutting edge is straight and along a grid line;
 * 3.  each piece has only one cherry on it;
 * 4.  each cut must split the cake you currently cut two separate parts
 *
 * For example, assume that the cake has a grid of 3*4 unit squares on its top,
 * and there are three cherries on the top, as shown in the figure below.
 *                     +----+----+-----+----+
 *                     |    |  * |     |    |
 *                     +--------------------+
 *                     |    |    |  *  |    |
 *                     +--------------------+
 *                     |    |  * |     |    |
 *                     +----+----+-----+----+
 * One allowable slicing is as follows.
 *   +----+----+-----+----+    +----+----+---+---+   +----+----+---+---+
 *   |    |  * |     |    |    |    |  * |   |   |   |    |  * |   |   |
 * --------------------------  +-----------------+   +-----------------+
 *   |    |    |  *  |    |    +-----------------+   +---------+  +-------+
 *   +--------------------+    |    |    | * |   |   |    |    |  | * |   |
 *   |    |  * |     |    |    +-----------------+   +---------+  +-------+
 *   +----+----+-----+----+    |    |  * |   |   |   |    |  * |  |   |   |
 *                             +----+----+---+---+   +----+----+  +---+---+
 * For this way of slicing , the total length of the cutting edges is 2+4=6.
 * Input
 *
 * The input file contains multiple test cases. For each test case:
 * The first line contains three integers , n, m and k (1 ≤ n, m ≤ 20), where
 * n * m is the size of the unit square with a cherry on it . The two integers
 * show respectively the row number and the column number of the unit square in
 * the grid .
 * All integers in each line should be separated by blanks.
 *
 * Output
 *
 * Output an integer indicating the least total length of the cutting edges.
 *
 * 【Sample Input】
 *     3 4 3
 *     1 2
 *     2 3
 *     3 2
 * 【Sample Output】
 *     Case 1: 5
 */

#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;
#define min(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;
const int maxn = 25;
const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;

int dp[maxn][maxn][maxn][maxn];
bool flag[maxn][maxn];     // Flag for whether there is a cherry

int fun(int a, int b, int c, int d)
{
	int i, j, cnt = 0, Min = INF;

	if (dp[a][b][c][d] != -1)  // already done
		return dp[a][b][c][d];

	for(i = a; i <= c; i++) {
		for(j = b; j <= d; j++)	{
			if(flag[i][j])
				cnt++;
		}
	}
	if(cnt <= 1)            // less than 2
	{
		return dp[a][b][c][d] = 0;
	}

	for (i = a; i < c; i++)  // Cut horizontally
		Min = min(Min, fun(a, b, i, d) + fun(i + 1, b, c, d) + (d - b + 1));
	for (i = b; i < d; i++)  // Cut vertically
		Min = min(Min, fun(a, b, c, i) + fun(a, i + 1, c, d) + (c - a + 1));
	return dp[a][b][c][d] = Min;
}

int main()
{
	int n, m, k, ans;
    int cas = 1;
    int x,y;

#ifdef FILE_INOUT
	freopen("input.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
	while (cin >> n >> m >> k) {
		memset(dp, -1, sizeof(dp)/sizeof(int));
		memset(flag, false, sizeof(flag)/sizeof(bool));

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			flag[x][y]=1;
		}
		ans = fun(1, 1, n, m);
		cout << "Case " << cas++ << ": " << ans << '\n';
	}
#ifdef FILE_INOUT
	fclose(stdin);
	fclose(stdout);
#endif
    return 0;
}