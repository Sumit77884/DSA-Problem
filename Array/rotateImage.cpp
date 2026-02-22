class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // step 1. traspose
        int n = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        // step 2. reverse row wise
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};