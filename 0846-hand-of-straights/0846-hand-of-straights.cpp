class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       int n = hand.size();
        
        // Edge Case: Agar cards barabar groups me bat hi nahi sakte
        if (n % groupSize != 0) {
            return false;
        }
        
        // Step 1: Frequency map banana
        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }
        
        // Step 2: Unique elements ko Min-Heap me daalna
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto const& [card, count] : freq) {
            minHeap.push(card);
        }
        
        // Step 3: Groups banana shuru karna
        while (!minHeap.empty()) {
            int first_card = minHeap.top();
            
            // Agar yeh card pehle hi kisi group me use ho chuka hai
            if (freq[first_card] == 0) {
                minHeap.pop();
                continue;
            }
            
            // Ab first_card se lekar next consecutive groupSize cards check karo
            for (int i = 0; i < groupSize; i++) {
                int current_card = first_card + i;
                
                // Agar beech ka koi card missing hai ya uski frequency khatam ho gayi hai
                if (freq[current_card] == 0) {
                    return false;
                }
                
                // Card use kiya toh frequency 1 se kam karo
                freq[current_card]--;
            }
        }
        
        return true;
    }
};