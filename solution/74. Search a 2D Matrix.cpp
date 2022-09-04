class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int row = matrix.size();
        const int col = matrix[0].size();
        int left = 0;
        int right= row * col;

        while(left < right)
        {
            const int middle = (left + right)/2;
            const int i = middle/col;
            const int j = middle %col;
            cout<<i <<" "<<j<<endl;
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j] < target)
            {
                left = middle+1;
            }
            else 
            {
                right = middle;
            }
        }
        return false;
    }
};