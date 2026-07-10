class Solution {
public:
    int getAns(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        int left = 0, count = 0, sum = 0;
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int right = 0; right < n; right++) {
            if (freq[nums[right]] == 0) {
                count++;
            }
            freq[nums[right]]++;

            while (count > k) {
                freq[nums[left]]--;
                
             if (freq[nums[left]] == 0) { count--; }

                left++;
            }

            sum += (right - left + 1);
        }
        return sum;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getAns(nums,k)-getAns(nums,k-1);
    }
};