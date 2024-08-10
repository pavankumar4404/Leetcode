class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=INT_MIN;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1') height[j]++;
                else
                    height[j]=0;
            }
            int area=largestRectangleArea(height);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};