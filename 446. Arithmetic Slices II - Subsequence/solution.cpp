class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if( n < 3) return 0;        
        vector<unordered_map<int,int>> subsequence (n);

        int solution = 0;
        for(int i = 1; i < n; ++i) {

            for(int j = i-1; j >= 0; --j) {

                
                
                long long overflow1 = nums[i];
                long long overflow2 = nums[j];

                if(overflow1-overflow2 > INT_MAX || overflow1-overflow2<INT_MIN) continue;
                int diff = nums[i] - nums[j];
                subsequence[i][diff] +=1;

                if (subsequence[j].count(diff)){ // because diff can be 0
                    subsequence[i][diff] += subsequence[j][diff];
                    solution += subsequence[j][diff];
                }

            }

        }

        return solution;
    }
};