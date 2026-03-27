class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        k = k % n;
        if(k == 0) return true;

  
        for(int i = 0; i < mat.size(); i++){
            int repeat = -1;
       
            for(int j = 0; j < n; j++){
                // even: check left shift, odd: check right shift
                int shifted = (i % 2 == 0) ? (j + k) % n : (j - k + n) % n;
                if(mat[i][j] != mat[i][shifted]){
                    return false;
                }
            }
        }
        return true;
    }
};