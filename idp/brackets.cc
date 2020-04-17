// Brackets
//
// Time Limit: 1000MS
// Memory Limit: 65536K
//
// Description
//
// We give the following inductive definition of a “regular brackets” sequence:
//   the empty sequence is a regular brackets sequence,
//   if s is a regular brackets sequence, then (s) and [s] are regular brackets
//   sequences, and if a and b are regular brackets sequences, then ab is a
//   regular brackets sequence.
//   no other sequence is a regular brackets sequence.
//
// For instance,all of the following character sequences are regular brackets
// sequences:
//
// (), [], (()), ()[], ()[()]
//
// while thefollowing character sequences are not:
//
// (, ], )(, ([)], ([(]
//
// Given a brackets sequence of characters a1a2 … an, your goal is to find the
// length of the longest regular brackets sequence that is a subsequence of s.
// That is, you wish to find the largest m such that for indicesi1, i2,  …, im
// where 1 ≤ i1 < i2 < … <im ≤ n, ai1 ai2 … aim is a regular brackets sequence.
//
// Given the initial sequence ([([]])], the longest regularbrackets subsequence
// is[([])].
//
// Input
//
// The input test file will contain multiple test cases. Each input test case
// consists of a single line containing only the characters(, ), [, and]; each
// input test will have length between 1 and 100, inclusive. The end-of-file is
// marked by a line containing the word “end” and should not be processed.
//
// Output
//
// For each input case, the program should print the length of the longest
// possible regular brackets subsequence on a single line.
//
// Sample Input
//
// ((()))
//
// ()()()
//
// ([]])
//
// )[)(
//
// ([][][)
//
// end
//
// Sample Output
//
// 6
//
// 6
//
// 4
//
// 0
//
// 6

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define min(x, y) ((x) < (y) ? (x) : (y))

const int max_n = 1000;

int dp[max_n][max_n] = {{0, 0},};
string s;


int main()
{
	while (cin >> s && s[0] != 'e') {
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
	  cout << dp[0][n - 1] << endl;
   }
   return 0;
}