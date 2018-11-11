# Codeforces 996A Hit the Lottery using Greedy & Dynamic Programming

This repository will solve problem [996A Hit the Lottery](https://codeforces.com/problemset/problem/996/A) using Greedy Algorithm and Dynamic Programming, and analyze each of its perks to find which is better.

### Team Members:
- Johny Huang
- Leon Chrisdion
- Nicholas Prawiro Chen
- Sutedja The Hoping

### Programming Language:
- C++ 11

### Installation/Running Instructions:
- Compile and execute the source code that can be found in this repository using GNU G++11 5.1.0

### Problem:
<p align="center">
<b>Hit the Lottery</b><br>
<b>time limit per test: 1 second</b><br>
<b>memory limit per test: 256 megabytes</b><br>
<b>input standard input</b><br>
<b>output standard output</b><br>  
</p>

<p align="justify">
Allen has a LOT of money. He has n dollars in the bank. For security reasons, he wants to withdraw it in cash (we will not disclose the reasons here). The denominations for dollar bills are 1, 5, 10, 20, 100. What is the minimum number of bills Allen could receive after withdrawing his entire balance?
</p>
Input:

The first and only line of input contains a single integer n (1≤n≤109).


Output:

Output the minimum number of bills that Allen could receive.

### Sample Testing:

**Sample #1:**

Input:
```
125
```
Output:
```
3
```

**Sample #2:**

Input:
```
43
```

Output:
```
5
```

**Sample #3:**

Input:
```
1000000000
```
Output:
```
10000000
```

### Note:

In the first sample case, Allen can withdraw this with a 100 dollar bill, a 20 dollar bill, and a 5 dollar bill. There is no way for Allen to receive 125 dollars in one or two bills.

In the second sample case, Allen can withdraw two 20 dollar bills and three 1 dollar bills.

In the third sample case, Allen can withdraw 100000000 (ten million!) 100 dollar bills.

### Explanation:

This problem is a classic minimum coin change problem. The objective of this problem is to find the minimum number of bills we use to make a specified amount of money, given that we have unlimited amounts of 1, 5, 10, 20, 100 bills.

### Greedy Solution:

The greedy way of solving this problem is by taking as many 100 bills as possible, followed by 20 bills, 10 and so on. This is done by repeatedly subtracting the given amount of money by 100 until it is less than 100 and incrementing the **number of bills used** on each iteration. We then move on repeating the process but with the next bill in a descending order until we are done with all the bills. 

The **number of bills used** will the minimum number of bills, and this solution is possible because each of the bill in the sequence is the divisor the the next bill.

The time complexity for this method will be **O(n)**, where **n** is the number of times the money will be subtracted by the bills.

### Dynamic Programming Solution:

The dynamic programming way of solving this problem is by making a **temporary table[]** to store the **minimum number of bills** in a bottom up manner to avoid recomputation. This is done by making a **table[]** of the size **n + 1** and filling it all with **infinity** except for **table[0]** where we will fill it with **0**. 

We then iterate through the amount of money **i** from **1** to our given money **n** and fill the respective table element with the minimum coins required to make up the money. This is done by iterating through all bills **m** for each amount of money **i**, if it is possible to subtract the money **i** by the bill **m**, then we subtract it and take the element in the table corresponding to the subtracted amount which will contain the minimum bill if we subtract the money **i** by the bill **m** already. If the result for using the bill **m** for this amount is less than the previous amount (using other bill), then we update **table[i]** with the new value that is **table[i-coins[j]]+ 1**. After iterating through all the money we will get our result which is the minimum bills required for money **n** in the **table[n]**.

The time complexity for this method will be **O(mn)**, where **m** is the number of bill types and **n** is the amount of money. This is because we iterate through all the **n** money 

### Analysis

Greedy:
- Time complexity: O(n)
- Memory allocation: 0 <= k <= 252

DP:

- Time complexity: O(nm)
- Memory allocation: 0 <= k <= some big number

Greedy is better than DP for this problem in terms of time and memory. Greedy uses a series of non-nested loops, while DP uses a nested loop. The memory allocation of greedy is also possibly less than DP as DP require the creation of array with size of **n**, where **n** may be a number as big as 10^9.
