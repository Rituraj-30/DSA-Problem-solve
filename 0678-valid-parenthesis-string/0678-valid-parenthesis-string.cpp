class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; // Minimum possible open brackets remaining
        int maxOpen = 0; // Maximum possible open brackets remaining
        
        for (char ch : s) {
            if (ch == '(') {
                minOpen++;
                maxOpen++;
            } else if (ch == ')') {
                minOpen--;
                maxOpen--;
            } else if (ch == '*') {
                minOpen--; // Treat as ')' or "" to minimize
                maxOpen++; // Treat as '(' to maximize
            }
            
            // Check 1: Agar maxOpen hi negative ho gaya, matlab balance hona namumkin hai
            if (maxOpen < 0) {
                return false;
            }
            
            // Check 2: minOpen kabhi 0 se chota nahi hona chahiye (invalid minimum bound)
            if (minOpen < 0) {
                minOpen = 0;
            }
        }
        
        // Agar minOpen 0 tak pahunch gaya, matlab humne sab perfectly balance kar liya hai
        return minOpen == 0;
    }
};