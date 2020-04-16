<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

# 区间规划

有一类问题可通过分阶段地划分问题来解决，我们称之为区间模型。

**区间DP**的关键是确定阶段中元素出现的顺序，并选择最佳的区间划分。

令 $dp[i,\;j]$ 表示状态 $i$ 到 $j$ 的最优解。$k$ 表示 $i$ 到 $j$ 的中间状态，则
 $dp[i,\;j]$ 等于 $dp[i,\;k]、dp[k,\;j]$ 以及将两者合并的值 （ $cost$ ）。

  $dp[i,\;j]=dp[i,\;k]+dp[k,\;j]+cost$

## 伪代码

区间DP最简单形式的伪代码(具体要根据题目修改)

	初始化DP数组
	zero(dp)
    for (int i = 1; i <= n; i++)
        dp[i][i]=初始值

    for (int len = 2; len <= n; len++)  //区间长度
        for(int i = 1; i <= n; i++)     //枚举起点
            int j = i + len - 1;        //区间终点
            if (j > n) break;       //越界结束
            for (int k = i; k < j; k++) //枚举分割点，构造状态转移方程
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + w[i][j]);

## 消除回文

我们有一个连续的序列，每个序列上面都是一个数字 $c[i]$，，消灭之后左右会合并，成
为一个新序列，问最少需要多少次才能够把整个序列消灭掉。

**回文指从左到右或从右到左读到的序列都是相同。**

### 分析

$[i,\;j]$ 之间的数字序列会有三种情况：
1. 只有一个元素（ $i=j$ ），仅需删除一次
2. $i$ 最后删除；$[i+1、\;j]$ 之间的数字序列删除次数增加1次；
3. $[i,\;j]$ 之间的 $k$ 与 $i$ 相同，解为 区间 $[i+1,\;k-1]$ 和  $[k+1,\;j-1]$
的删除次数之和。

**【最优子结构】**

$dp[i][j]$ 区间 $[i,\;j]$ 的删除次数。

**【边界】**

$$
dp[i][i] = 1 \\
dp[i][j] = j - i + 1
$$

**【状态转移公式】**

$$
dp[i][j]=\left\{\begin{array}{ll}
    0,\quad &i>j\\
    1, \quad &i=j\\
    min&\left\{
    \begin{array}{ll}
       dp[i][j]\\
       1+dp[i+1][j]\\
	   2+dp[i+1][j]\\
	   min(dp[i+i][k-1]+dp[k+1][j-1]),\quad i<k<j
	\end{array}
	\right.
\end{array}
\right.
$$

**【时间复杂度】**

$ O(n^3) $