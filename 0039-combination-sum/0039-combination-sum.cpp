class Solution {
public:
    set<vector<int>>s;
    void helper(int idx,int target,vector<int>& nums,vector<int>&combin,vector<vector<int>>&ans){
        if(idx==nums.size() || target<0){
            return ;
        }
          if(target==0){
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            
            return ;
        }

        combin.push_back(nums[idx]);

        helper(idx+1,target-nums[idx],nums,combin,ans);
        helper(idx,target-nums[idx],nums,combin,ans);

        combin.pop_back();

        helper(idx+1,target,nums,combin,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        helper(0, target,candidates, combin,ans);
        return ans;

    }
};