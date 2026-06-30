class Solution {
public:
   
    const vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void solve(int idx,string &digits,string curr,vector<string>&ans){
        if(idx==digits.length()){
            ans.push_back(curr);
            return ;
        }

        int digit=digits[idx]-'0';
        string letters=keypad[digit];

        for (int i = 0; i < letters.length(); i++) {
            solve(idx + 1, digits, curr + letters[i], ans);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr="";

        solve(0,digits,curr,ans);

        return ans;

        
    }
};