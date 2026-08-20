class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i,
             int j) {
        visited[i][j] = 1;
        if(i+1 < grid.size() && grid[i+1][j] == '1' && visited[i+1][j]!=1){
            dfs(grid,visited,i+1,j);
        }
        if(i!=0 && grid[i-1][j] == '1' && visited[i-1][j]!=1){
            dfs(grid,visited,i-1,j);
        }
        if(j+1 < grid[0].size() && grid[i][j+1] == '1' && visited[i][j+1]!=1){
            dfs(grid,visited,i,j+1);
        }
        if(j !=0 && grid[i][j-1] == '1' && visited[i][j-1]!=1){
            dfs(grid,visited,i,j-1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<int>> visited(grid.size(),
                                    vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] !=1) {
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};