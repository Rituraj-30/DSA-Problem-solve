class Solution {
public:
    // void helper(vector<int>& nums, int idx, vector<int> ans,
    //             vector<vector<int>>& getAll) {
    //     if (idx == nums.size()) {
    //         getAll.push_back({ans});
    //         return;
    //     }
    //     ans.push_back(nums[idx]);
    //     helper(nums, idx + 1, ans, getAll);
    //     ans.pop_back();
    //     helper(nums, idx + 1, ans, getAll);
    // }

    vector<vector<int>> subsets(vector<int>& nums) {

        // vector<int> ans;
        vector<vector<int>> getAll;
        int n = nums.size();
        int set = 1<< n;
        // helper(nums,0,ans,getAll);

        for (int i = 0; i < set; i++) {
            vector<int> ans;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    ans.push_back(nums[j]);
                }
            }
            getAll.push_back(ans);
        }

        return getAll;
    }

       
};