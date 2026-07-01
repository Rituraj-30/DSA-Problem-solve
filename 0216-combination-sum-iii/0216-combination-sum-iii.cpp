class Solution {
public:
    void helper(int st, int k,int n, vector<int>&vec,vector<vector<int>>&ans){
        if(k==0 && n==0){
            ans.push_back(vec);
            return ;
        }
        if(k==0 || n<0 || st>9)return ;
        vec.push_back(st);

        helper(st+1,k-1,n-st,vec,ans);
        vec.pop_back();
        helper(st+1,k,n,vec,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>vec;
        vector<vector<int>>ans;

        helper(1,k,n,vec,ans);

        return ans;


        
    }
};