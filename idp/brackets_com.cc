// 括号匹配
//
// 给你一个字符串，里面只包含"(",")","[","]"四种符号，请问你需要至少添加多少个括
// 号才能使这些括号匹配起来。
// 如：
// []是匹配的
// ([])[]是匹配的
// ((]是不匹配的
// ([)]是不匹配的
//
// 输入
//
// 第一行输入一个正整数N，表示测试数据组数(N <= 10)
// 每组测试数据都只有一行，是一个字符串S，S中只包含以上所说的四种字符，S的长度不
// 超过100
//
// 输出
//
// 对于每组测试数据都输出一个正整数，表示最少需要添加的括号的数量。每组测试输出
// 占一行
//
// 样例输入
//  4
//  []
//  ([])[]
//  ((]
//  ([)]
//
// 样例输出
//  0
//  0
//  3
//  2

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define min(x, y) ((x) < (y) ? (x) : (y))

const int max_n = 1000;

int ans[max_n] = {0};
int dp[max_n][max_n] = {{0, 0},};
string s;

int main()
{
	int t, m;
	cin >> t;
	m = t;
	while (t-- && cin >> s) {
		int n = s.length();
		memset(dp, 0, sizeof(dp));
		for (int len = 1; len < n; len++) {
		   for (int i = 0; i < n; i++) {
			   int j = i + len;
			   if (j > n) break;
			   if (s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']') {
				   dp[i][j] = dp[i + 1][j - 1] + 2;
			   }
			   for (int k = i; k < j; k++)
				   dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
		  }
	  }
	  ans[m - t] =  n - dp[0][n - 1];
   }
   for (int i = 1; i <= m; i++)
	   cout << ans[i] << '\n';
   cout << endl;
   return 0;
}