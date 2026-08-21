class Solution {
public:

    void traverse(int i,int j, vector<vector<int>> &visited, vector<vector<int>>& grid,queue<pair<int,int>> &q ){
        visited[i][j] = 1;
        if(i+1 < grid.size() && grid[i+1][j] == 1 && visited[i+1][j]!=1){
            visited[i+1][j] = 1;
            q.push({i+1,j});
            grid[i+1][j] = 2;
        }
        if(i!=0 && grid[i-1][j] == 1 && visited[i-1][j]!=1){
            visited[i-1][j] = 1;
            q.push({i-1,j});
            grid[i-1][j] = 2;
        }
        if(j+1 < grid[0].size() && grid[i][j+1] == 1 && visited[i][j+1]!=1){
            visited[i][j+1] = 1;
            q.push({i,j+1});
            grid[i][j+1] = 2;
        }
        if(j !=0 && grid[i][j-1] == 1 && visited[i][j-1]!=1){
            visited[i][j-1] = 1;
            q.push({i,j-1});
            grid[i][j-1] = 2;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int flag = 0;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    flag = 1;
                }
                if(grid[i][j]== 1)flag = 1;
            }
        }
        if(flag == 0)return 0;
        vector<vector<int>> visited(grid.size(),
                                    vector<int>(grid[0].size(), 0));
        int count = -1;
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int i=0; i<size; i++){
                pair<int,int> temp = q.front();
                q.pop();
                traverse(temp.first, temp.second, visited, grid,q);
            } 
        }
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
};