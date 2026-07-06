class Solution {
public:
    int getArea(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
            
        for (int i = n-1; i >=0; i--) {
            while (!st.empty() && height[st.top()] >= height[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int maxArea=0;


        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int curr=width*height[i];
            maxArea=max(maxArea,curr);

        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        int maxArea = 0;
        vector<int> height(col, 0);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            int area =getArea(height);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};