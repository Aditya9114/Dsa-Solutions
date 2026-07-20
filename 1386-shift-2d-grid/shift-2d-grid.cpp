class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        k %= (m*n);

        if(k==0) return grid;

        vector<int> nums;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(grid[i][j]);
            }
        }

        int rowPointer = k / n;      // corrected
        int colPointer = k % n;

        int pointer = 0;

        // Fill from shifted position to end
        for(int i=rowPointer;i<m;i++){
            for(int j=(i==rowPointer ? colPointer : 0); j<n; j++){
                grid[i][j] = nums[pointer++];
            }
        }

        // Fill remaining beginning
        for(int i=0;i<m && pointer<nums.size();i++){
            for(int j=0;j<n && pointer<nums.size();j++){
                grid[i][j] = nums[pointer++];
            }
        }

        return grid;
    }
};