// 题目描述：
// 给出1-n的两个排列P1和P2，求它们的最长公共子序列。
//
// 输入格式：
// 第一行是一个数n，
// 接下来两行，每行为n个数，为自然数1-n的一个排列。
//
// 输出格式：
// 一个数，即最长公共子序列的长度
//
// 输入样例：
// 5
// 3 2 1 4 5
// 1 2 3 4 5
// 输出样例：
// 3
//
// 【数据规模】
// 对于50%的数据，n≤1000
// 对于100%的数据，n≤100000
#include <iostream>
#include <cstdio>

using namespace std;
const int max_lin = 100000 + 5;

int dp[max_lin];
int a[max_lin], b[max_lin];

// 本题虽然一道LCS问题，但是N特别大，依次不仅时间复杂度而且空间复杂度
// 均很高。
//
// 由于输入是1~n的排列，如果其中一个排列是1、2、3、…、n，那么另一个序列的
// LIS即为它们的LCS。
//
// 将第二个序列转换为第一个序列的映射，然后求其LIS即可。
int lcs2(int n)
{
	int i, v, pos = 0;

	for (i = 0; i < n; i++) {
		cin >>	v;
		a[v] = i;
	}

	for (i = 0; i < n; i++)	{
		cin >> v;
		b[i] = a[v]; //把b数组按照a数组的映射规则进行映射
	}
	for (i = 0; i < n; i++)
		dp[i]=0;

	dp[0] = b[0];
	for (i = 1; i < n; i++)	{
		if (b[i] >= dp[pos])
			dp[++pos] = b[i];
		else // 二分法插入
			dp[lower_bound(dp, dp + pos + 1, b[i]) - dp] = b[i];
	}
	return pos + 1;
}

int main()
{
    int n;
#ifdef FILE_INOUT
	freopen("input.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
    while (cin>>n)
    {
        cout << lcs2(n) << endl;
    }
#ifdef FILE_INOUT
	fclose(stdin);
	fclose(stdout);
#endif
    return 0;
}