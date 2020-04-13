// 合唱队形
//
// 题目描述:
//
// N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换
// 位置就能排成合唱队形。
//
// 合唱队形定义：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为
// T1, T2, …, TK，则他们的身高满足
// T1 < T2 < … < Ti， Ti > Ti+1 > … > TK (1 <= i <= K)。
//
// 要求：已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排
// 成合唱队形
//
//【题目输入】
// 第一行是一个整数N(2<=N<=100)，表示同学的总数。第一行有n个整数，用空格分隔，
// 第i个整数Ti(130<=Ti<=230)是第i位同学的身高(厘米)
//
//【题目输出】
// 只包含一个整数，就是最少需要几位同学出列
//
// 【样例输入】
// 8
// 186 186 150 200 160 130 197 220
//
//【样例输出】
// 4

#include <iostream>
#include <cstdio>

#define max(x, y) ((x) > (y) ? (x) : (y))
const int max_num = 105;

using namespace std;

class chorus {
public:
	chorus() {
		cin >> num;
		lis_r[num+1] = lis_l[0] = 0;
		for (int i = 1; i <= num; i++) {
			cin >> h[i];
			lis_r[i] = lis_l[i] = 1;
		}
	};
	~chorus() {};
	int leave();
protected:
	int num;
	void update_l(int i);
	void update_r(int i);
	int h[max_num];
	int lis_r[max_num];
	int lis_l[max_num];
};

void chorus :: update_l(int n)
{
	int i;
	for (i = n - 1; i >= 1 && h[i] > h[n]; i--);
	lis_l[n] = lis_l[i] + 1;
}
void chorus :: update_r(int n)
{
	int i;
	for (i = n + 1; i <= num && h[i] > h[n]; i++);
	lis_r[n] = lis_r[i] + 1;
}

int chorus :: leave()
{
	int i, lis = 0;
	for (i = 2; i <= num; i++) {
		update_l(i);
		update_r(num - i + 1);
	}
	for (i = 1; i <= num; i++)
		lis = max(lis, lis_r[i] + lis_l[i]);

	return num - (lis - 1);
}

int main()
{
	class chorus c;
	cout << c.leave() << endl;
	return 0;
}