// 挖地雷
//
// 题目描述:
//     在一个地图上有N个地窖（N<=20），每个地窖中埋有一定数量的地雷。同时，给出
//     地窖之间的连接路径。当地窖及其连接的数据给出之后，某人可以从任一处开始挖
//     地雷，然后可以沿着指出的连接往下挖（仅能选择一条路径），当无连接时挖地雷
//     工作结束。设计一个挖地雷的方案，使某人能挖到最多的地雷。
//
// 输入格式：
//     输入文件mine.in有若干行。
//     第1行只有一个数字，表示地窖的个数N。
//     第2行有N个数，分别表示每个地窖中的地雷个数。
//     第3行至第N+1行表示地窖之间的连接情况：
//     第3行有n-1个数（0或1），表示第一个地窖至第2个、第3个、…、第n个地窖有否路
//     径连接。如第3行为1 1 0 0 0 … 0，则表示第1个地窖至第2个地窖有路径，至第3个
//     地窖有路径，至第4个地窖、第5个、…、第n个地窖没有路径。
//     第4行有n-2个数，表示第二个地窖至第3个、第4个、…、第n个地窖有否路径连接。
//     … …
//     第n+1行有1个数，表示第n-1个地窖至第n个地窖有否路径连接。（为0表示没有路
//     径，为1表示有路径）。
//
// 输出格式：
//     输出文件wdl.out有两行数据。
//     第一行表示挖得最多地雷时的挖地雷的顺序，各地窖序号间以一个空格分隔，不得
//     有多余的空格。
//     第二行只有一个数，表示能挖到的最多地雷数。
//
// 输入样例
//     5
//     10 8 4 7 6
//     1 1 1 0
//     0 0 0
//     1 1
//     1
//
// 输出样例
// 1 3 4 5
// 27

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int max_n = 100;

class mines {
public:
	mines() {};
	~mines() {};
	void init(void);
	int ans(void);
protected:
	int n;
	int m[max_n];
	int dp[max_n];
	int suf[max_n];
	int c[max_n][max_n];
	void dig(void);
} mine;

void mines::init(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		dp[i] = m[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cin >> c[i][j];
			c[j][i] = c[i][j];
		}
	}
}

void mines::dig(void)
{
	for (int i = n - 1; i >= 1; i--) {	 
		int l = 0, k = 0;
		for (int j = i + 1; j <= n; j++) {
			if (c[i][j] && dp[j] > l){
				l = dp[j];
				k = j;
			}
		}		 
		dp[i] = m[i] + l;		 
		suf[i] = k; 
	} 
}

int mines::ans(void)
{
	int k = 1, maxn = 0;
	
	dig();
	for (int i = 1; i <= n; i++) {
		if (dp[i] > dp[k])
			k = i;
	}
	maxn = dp[k];
	cout << k;
	k = suf[k];
	while (k != 0) {
		cout << ' ' <<k;
		k = suf[k];
	}
	cout << '\n';
	return maxn;
}

int main()
{
	mine.init();
	cout << mine.ans() << endl;
	return 0;
}