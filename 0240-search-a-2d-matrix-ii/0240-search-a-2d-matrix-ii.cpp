class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j=matrix[0].size()-1;
        int n=matrix.size();
        int i=0;
        while(j>=0 && i<n)
        {
            if(matrix[i][j]==target)
            return true;
            else if(matrix[i][j]>target)
            j--;
            else 
            i++;
        }
        return false;
    }
};