# 动态规划算法例题集

**动态规划「Dynamic programming」**

**DP**

![DP](https://tse2-mm.cn.bing.net/th/id/OIP.9E03l6gZjqN3feiCvJaaUwHaF7?w=171&h=160&c=7&o=5&pid=1.7 "DP")

解决问题最强大的技术之一是将问题分解为较小，较容易解决的部分。 较小的问题不那么
令人费解，它们使我们可以更专注于研究整个问题的细节。动态规划算法的核心是分而治之。
该方法通常从问题中删除一个元素，以形成待解决的较小问题。待该较小问题的解决方案后，
再以正确的方式添加回被删除的元素。

## 动态规划的特征
**<font size=4>最优化</font>**

无论过去的状态和决策如何，余下的决策必须构成最优策略。简单来说就是一个最优化
策略的子策略总是最优的。

**<font size=4>无后效性</font>**

收益只与当前状态和决策相关，与达到该状态的方式无关。

**<font size=4>子问题的重叠性</font>**

避免冗余、重复计算，将数级的暴力搜索算法改进到了具有多项式时间复杂度的算法。

## 动态规划的关键点
* **<font size=4>最优子结构</font>**

* **<font size=4>边界</font>**

* **<font size=4>状态转移公式</font>**

## 线性DP

决定线性DP状态的约束条件是线性的。

### 典型的线性DP问题：

1.  爬楼梯
2.  数字金字塔
3.  最长上升子序列（LIS）
4.  最长公共子序列（LCS）

## 区间DP

区间DP将待解决问题划分为不同的阶段。首先在较小的区间上获得最优解，然后再将小区间
合并求得最终解。

**实现思路**

假设状态转移数组为dp[n][m]，dp[i][j]表示从状态i到状态j的最优解。

```
    for (int i = 1; i <= n; i++)
        dp[i][i]=初始值

    for (int len = 2; len <= n; len++) {  //区间长度
        for(int i = 1; i <= n; i++)  {       //枚举起点
            int j = i + len - 1;           //区间终点
            if (j > n)
                break;           //越界结束
            for (int k = i; k < j; k++)   //枚举分割点，构造状态转移方程
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + w[i][j]);
        }
    }
```

### 典型区间DP问题：

1. 石子合并
2. 括号匹配
3. 整数划分
4. 凸多边形三角划分
5. 背包


