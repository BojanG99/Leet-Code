class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();


        vector<pair<int,int>> endTimeWithPosition (n);

        for(int i = 0; i<n; ++i) {

            endTimeWithPosition[i] = {endTime[i], i};

        }

        sort(endTimeWithPosition.begin(), endTimeWithPosition.end(), mySort);

        vector<int> dp(n + 1);
        dp[0]=0;
        for(int i = 0; i < n; ++i) {
            int index = endTimeWithPosition[i].second;
            int lastNonConflictIndx = upper_bound(endTimeWithPosition.begin(), endTimeWithPosition.begin() + i, startTime[index] , [&](int time, const auto& job) -> bool {
                return time < job.first;
            })- endTimeWithPosition.begin();
            dp[i + 1] = max(dp[i], dp[lastNonConflictIndx] + profit[index]);

        }
        
        return dp[n];
    }

    static bool mySort(pair<int, int>& a, pair<int, int>& b) {

            return a.first < b.first;

    }
};
