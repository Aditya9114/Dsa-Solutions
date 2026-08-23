class Solution {
public:

    void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int &flag,
    int i, int j, queue<pair<int,int>> &q){
        visited[i][j] = 1;
        q.push({i,j});
        if(i==board.size()-1 || j==board[0].size()-1 || i==0 || j==0){
            flag = 1;
        }
        //down
        if(i+1 != board.size() && board[i+1][j] == 'O' && visited[i+1][j]!=1){
            dfs(board,visited,flag,i+1,j,q);
        }
        
        //left
        if(j != 0 && board[i][j-1] == 'O' && visited[i][j-1]!=1){
            dfs(board,visited,flag,i,j-1,q);
        }

        //right
        if(j+1 != board[0].size() && board[i][j+1] == 'O' && visited[i][j+1]!=1){
            dfs(board,visited,flag,i,j+1,q);
        }

        //up
        if(i != 0 && board[i-1][j] == 'O' && visited[i-1][j]!=1){
            dfs(board,visited,flag,i-1,j,q);
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> visited(row,vector<int>(col,0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(visited[i][j]!=1 && board[i][j] == 'O'){
                    int flag = 0;
                    queue<pair<int,int>> q;
                    dfs(board,visited,flag,i,j,q);
                    if(flag == 0){
                        int size = q.size();
                        for(int k =0; k<size; k++){
                            pair<int,int>it = q.front();
                            board[it.first][it.second] = 'X';
                            q.pop();
                        }
                    }
                }
            }
        } 
    }
};