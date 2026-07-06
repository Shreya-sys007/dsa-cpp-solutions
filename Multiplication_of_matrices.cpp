//what is vector<int>(p,0) ? in vector<vector<int>>() ?-----Here we mean that in a 2D vec create 'm' copies of a vector with
//size p and all values 0
//Use += in line 17. Else you'll be overwriting the vals

//TC: O(m*n*p);
//SC: O(1);

class Solution {
  public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        // Code here
        int m = mat1.size();
        int n = mat1[0].size();
        int p = mat2[0].size();
        
        vector<vector<int>>c(m, vector<int>(p, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j< p; j++){
                c[i][j] = 0;
                for(int k = 0; k<n; k++){
                    c[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return c;
    }
};
