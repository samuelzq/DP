// 剑客决斗
// 描述
//
//    在路易十三和红衣主教黎塞留当权的时代，发生了一场决斗。n个人站成一个圈，依
//    次抽签。抽中的人和他右边的人决斗，负者出圈。这场决斗的最终结果关键取决于决
//    斗的顺序。现书籍任意两决斗中谁能胜出的信息，但“A赢了B”这种关系没有传递性。
//    例如，A比B强，B比C强，C比A强。如果A和B先决斗，C最终会赢，但如果B和C决斗在
//    先，则最后A会赢。显然，他们三人中的第一场决斗直接影响最终结果。
//
//    假设现在n个人围成一个圈，按顺序编上编号1~n。一共进行n-1场决斗。第一场，其
//    中一人（设i号）和他右边的人（即i+1号，若i=n，其右边人则为1号）。负者被淘汰
//    出圈外，由他旁边的人补上他的位置。已知n个人之间的强弱关系（即任意两个人之间
//    输赢关系）。如果存在一种抽签方式使第k个人可能胜出，则我们说第k人有可能胜出，
//    我们的任务是根据n个人的强弱关系，判断可能胜出的人数。
//
// 输入
//    第一行是一个整数N(1<=N<=20)表示测试数据的组数。
//    第二行是一个整数n表示决斗的总人数。(2<=n<=500)
//    随后的n行是一个n行n列的矩阵，矩阵中的第i行第j列如果为1表示第i个人与第j个人
//    决斗时第i个人会胜出，为0则表示第i个人与第j个人决斗时第i个人会失败。
//
// 输出
//    对于每组测试数据，输出可能胜出的人数，每组输出占一行
//
// 样例输入
//        1
//        3
//        0 1 0
//        0 0 1
//        1 0 0
//
// 样例输出
//        3

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int max_lin = 0x505;

class swordsman {
#define round_up(x) (((x) + 1) % num)
public:
	swordsman() {
		memset(m, 0, sizeof(m));
	};
	~swordsman() {};
	void init(void) {
		cin >> num;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cin >> w[i][j];
			}
			m[i][round_up(i)] = true;
		}
	};
	int winner(void);
protected:
	bool meet(int i, int j);
	int w[max_lin][max_lin];
	bool m[max_lin][max_lin];
	int num;
} sw;

bool swordsman::meet(int i, int j)
{
	for (int g = round_up(i); g != j; g = round_up(g)) {
		if (m[i][g] && m[g][j] && (w[i][g] || w[j][g])) {
			m[i][j] = true;
			break;
		}
	}
	return m[i][j];
}

int swordsman::winner(void)
{
	int l;

	for (int i = 1; i < num; i++) {
		for (int f = 0; f < num; f++) {
			l = round_up(f + i);
			if (w[f][l])
				continue;
			meet(f, l);
		}
	}
	l = 0;
	for (int i = 0; i < num; i++) {
		if (m[i][i])
			l++;
	}
	return l;
}

int main()
{
	int n = 0;
	cin >> n;
	while (n--)	{
		sw.init();
		cout << sw.winner() << endl;
	}
	return 0;
}