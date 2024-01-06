# Solutions

# Task
[![LeetCode](https://img.shields.io/badge/LeetCode-Solutions-brightgreen)](https://leetcode.com/problems/maximum-profit-in-job-scheduling)

# Aproach
Sort jobs by End Time. For each job i, we find latest job before i that is non overlapping with i, and calculate max profit with dp[i+1] = max (dp[i], dp[lastNonConflictIndx] + profit[i])
# Time complexity

O(nlogn) because for each element we do upper bound search ( O(logn) for each) and sorting is O(nlogn)

# Space complexity

O(n) because we need separate vector for keeping index after sorting.
