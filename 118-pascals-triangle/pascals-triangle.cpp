class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        if(numRows < 2)return triangle;
        triangle.push_back({1,1});
        int prevRow = 1;
        for(int i=2; i<numRows;i++){
            vector<int> vec;
            vec.push_back(1);
            for(int j=0; j<i-1;j++){
                int num = triangle[prevRow][j] + triangle[prevRow][j+1];
                vec.push_back(num);
            }
            prevRow++;
            vec.push_back(1);
            triangle.push_back(vec);
        }
        return triangle;
    }
};