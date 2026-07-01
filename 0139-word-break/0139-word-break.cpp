class Solution {
public:
    unordered_map<int, bool> memo;
    bool FindWord(int st,string s,  unordered_set<string> &dict){
        if(st==s.size()) return true;

        if (memo.find(st) != memo.end()) {
            return memo[st];
        }

        for(int end=st+1;end<=s.size();end++){

            string part= s.substr(st,end-st);

            if(dict.find(part)!=dict.end()){
                if(FindWord(end,s,dict))
                return memo[st] = true;

            }
        }
        return memo[st] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict ) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return FindWord(0,s,dict);

    }
};