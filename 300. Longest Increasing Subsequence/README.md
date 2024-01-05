#Solutions

#Task
[![LeetCode](https://img.shields.io/badge/LeetCode-Solutions-brightgreen)](https://leetcode.com/problems/longest-increasing-subsequence)

#Aproach
Keep sorted vector and using lower bound for each element find max increasing subsequence of elements before that. longest increasing subsequence is size of that vector.

#Time complexity

O(nlogn) because for each element we do lower bound search ( O(logn) for each)

#Space complexity

O(n) because we need separate vector.
