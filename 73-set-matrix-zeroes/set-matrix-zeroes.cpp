class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int,int>, int> mpp;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    mpp[{i,j}] = 1;
                }
            }
        }
        for(auto x : mpp){
            int row = x.first.first;
            int col = x.first.second;
            for(int i=0; i<matrix[0].size(); i++){
                matrix[row][i] = 0;
            }
            for(int j=0; j<matrix.size();j++){
                matrix[j][col] = 0;
            }
        }
    }
};