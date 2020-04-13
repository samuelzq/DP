// 利用树状数组解决LIS

#include <iostream>
#include <algorithm>
using namespace std;

//#define max(x, y) ((x) > (y) ? (x) : (y))

const int max_lin = 200 + 0xAC;

class s_node {
public:
	s_node() {};
	s_node(int& i, int v = 0) {
		val = v;
		idx = i;
	}
	s_node(const class s_node& node) {
		val = node.val;
		idx = node.idx;
	}
	~s_node() {};
	int index() const {return idx;}
	int value() const{return val;}
	bool operator < (s_node s) {
		return val == s.val ? idx > s.idx : val < s.val;
	}
private:
	int val;     // input value
	int idx;

};

class dp{
public:
	dp() {
		int n, v;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> v;
			class s_node n(i, v);
			w[i] = n;
			f[i] = 0;
		}
		d = n;
		sort(w + 1, w + n + 1);
	};
	~dp() {};
	int lis(void);
private:
	class s_node w[max_lin];
	int f[max_lin];
	int d;
	void update(int idx, int x);
	int querry(int idx);
};

#define lowbit(i)  ((i) & (-i))

void dp::update(int i, int x)
{
	for (; i <= d; i += lowbit(i))
		f[i] = max(f[i], x);
}

int dp::querry(int i)
{
	int lis = 0;
	for (; i >= 1; i -= lowbit(i))
		lis = max(f[i], lis);
	return lis;
}

int dp::lis(void)
{
	for (int i = 1; i <= d; ++i)
		update(w[i].index(), querry(w[i].index()) + 1);
	return querry(d);
}

int main()
{
	class dp dp;
	cout << dp.lis() << endl;
	return 0;
}