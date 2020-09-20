[TOC]

### 回顾
#### 递归
```

void recursion(int level, int param) { 
  // recursion terminator
  if (level > MAX_LEVEL) { 
  // process result 
    return ; 
  }

  // process current logic 
  process(level, param);

  // drill down 
  recursion(level + 1, param);

  // reverse the current level status if needed
}

```
#### 分治
```

int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) {
    process_result
    return return_result;
  } 

  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...

  // merge
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status
 
  return 0;
}

```

#### 经验

* 避免人肉递归
* 找到最近最简问题，将其拆解成可重复解决的逻辑
* 数学归纳法思维


### 动态规划定义
分治 + 最优子结构
动态规划和分治没有本质区别，都需要找到重复子问题。两者的区别在于，动态规划需要构建最有子结构。

### 例题
#### 题目：Fibonacci数列 - 一维DP
Bottom up + memorization
#### 题目：路径计数 - 二维DP
#### 动态规划关键点

* 最优子结构 dp[n] = best_of(dp[n-1], dp[n-2], ...)
* 存储中间状态 dp[i]
* 难点在于状态的定义。
* 递归方程（状态转移方程）
    * Fib：dp[i] = dp[i-1] + dp[i-2]
    * 二维路径：dp[i][j] = dp[i+1][j] + dp[i][j+1]

#### 题目：最长公共子序列 - 字符串DP



#### 题目：三角形最小路径和
```
triangle[i][j] = triangle[i][j] + min(trangle[i+1][j], triangle[i+1][j+1]
```

#### 题目：最大子序列和
```
nums[i] = max(0, dp[i-1]) + nums[i]
```

#### 题目：零钱兑换 - 需要滚瓜烂熟
```
dp[i] = min(dp[i], dp[i-coins[j]] + 1)
```

#### 打家劫舍
```
dp[i] = max(dp[i-1], nums[i] + dp[i-2])
```

### 小结
一定要多做多记，先把所有细节记下来。然后不断反复，浓缩。
打破自己的惯性思维，建立机器思维 - **找重复性**。

DP三步

1. 分治（子问题）
2. 递归&记忆化 或者 建立DP表，自底向上
3. DP方程