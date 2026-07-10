class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size())
            return "";

        vector<int> t_freq(128, 0);
        vector<int> windo(128, 0);

        for (char c : t) {
            t_freq[c]++;
        }

        int left = 0, stIdx = -1, mini = INT_MAX;
        int needCount = t.size();

        for (int right = 0; right < s.size(); right++) {

            char rightChar = s[right];
            windo[rightChar]++;

            if (t_freq[rightChar] > 0 &&
                windo[rightChar] <= t_freq[rightChar]) {
                needCount--;
            }

            while (needCount == 0) {
                if (right - left + 1 < mini) {
                    mini = right - left + 1;
                    stIdx = left;
                }

                char leftChar = s[left];
                windo[leftChar]--;

                if (t_freq[leftChar] > 0 &&
                    windo[leftChar] < t_freq[leftChar]) {
                    needCount++;
                }
                left++;
            }
        }

        return (stIdx == -1) ? "" : s.substr(stIdx, mini);
    }
};