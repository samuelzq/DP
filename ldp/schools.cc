// 山区小学
//
// 题目描述
//    政府在某山区修建了一条道路，恰好穿越总共m个村庄的每个村庄一次，没有回路或
//    交叉，任意两个村庄只能通过这条路来往。已知任意两个相邻的村庄之间的距离为
//    di（为正整数），其中，0 < i < m。为了提高山区的文化素质，政府又决定从m个村
//    中选择n个村建小学（设 0 < n < = m < 500 ）。请根据给定的m、n以及所有相邻村
//    庄的距离，选择在哪些村庄建小学，才使得所有村到最近小学的距离总和最小，计算
//    最小值。
//
// 输入
//    第1行为m和n，其间用空格间隔
//    第2行为(m-1) 个整数，依次表示从一端到另一端的相邻村庄的距离，整数之间以空
//    格间隔。
//
// 输入样例
//     10 2
//     3 1 3 1 1 1 1 1 3
//
// 输出样例
//     18

#include <iostream>
#include <cstdio>

using namespace std;
#define min(x, y) ((x) < (y) ? (x) : (y))
const int max_n = 505;

class school {
public:
	school() {
		cin >> m >> n;
		for (int i = 0; i <= m + 1; i++) {
			for(int j = 0; j <= m + 1; j++)
				dp[i][j] = 0x7fffffff;
		}

		a[1] = 0;
		for (int i = 2; i <= m; i++) {
			cin >> a[i];
			a[i] += a[i - 1];
		}
	};
	~school() {};
	int ans(void);
protected:
	int min_dist(int i, int j);
	void build_school(void);
	int m;
	int n;
	int a[max_n]; // 距离第一个村庄的距离
	int dp[max_n][max_n];
	int c[max_n][max_n];
} schools;

int school::min_dist(int i, int j)
{
	int ml = 0, mid = (i + j) / 2;
	for(int k = i; k < mid; k++)
		ml += abs(a[mid] - a[k]);
	for(int k = mid; k <= j; k++)
		ml += abs(a[k] - a[mid]);
	return ml;
}

void school::build_school(void)
{
	for (int i = 1; i <= m; i++) {
		for(int j = i + 1; j <= m; j++)
			c[i][j] = c[j][i] = min_dist(i, j);
	}

	for (int i = 1; i <= m; i++)
		dp[i][1] = c[1][i];

	for (int j = 2; j <= n; j++) {
		for (int i = j; i <= m; i++) {
			for (int k = j - 1; k < i; k++)
				dp[i][j] = min(dp[i][j], dp[k][j - 1] + c[k + 1][i]);
		}
	}
}

int school::ans(void)
{
	build_school();
	return dp[m][n];
}
int main()
{
	//freopen("T1.in", "r", stdin);
	//freopen("T1.out", "w", stdout);

	cout << schools.ans() << endl;
	return 0;
}