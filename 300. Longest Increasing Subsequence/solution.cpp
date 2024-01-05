class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> sorted_array;

        for( int num : nums) {

            auto lower_iterator = lower_bound(sorted_array.begin(), sorted_array.end(), num);
            if(lower_iterator == sorted_array.end()) {

                sorted_array.push_back(num);

            }
            else {

                *lower_iterator = num;

            }
        }

        return sorted_array.size();

    }
};