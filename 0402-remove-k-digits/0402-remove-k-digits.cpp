class Solution {
public:
    string removeKdigits(string num, int k) {
        string str = "";

        for (char ch : num) {
            while (!str.empty() && k > 0 && str.back() > ch) {
                k--;
                str.pop_back();
            }
            str.push_back(ch);
        }
        while (!str.empty() && k > 0) {
            k--;
            str.pop_back();
        }

        int st = 0;

        while (st < str.size() && str[st] == '0')
            st++;

        str = str.substr(st);

        return str.empty() ? "0" : str;
    }
};