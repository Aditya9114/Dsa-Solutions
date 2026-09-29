class Solution {
public:
    bool f(vector<vector<char>> &g, int i, int j, stack<char> &st,
           vector<vector<vector<int>>> &dp){                  // NEW: dp parameter
        if(i >= g.size() || j >= g[0].size()) return false;

        int sz = st.size();                                   // NEW: state before this cell
        if(dp[i][j][sz] != -1) return dp[i][j][sz];           // NEW: already solved

        bool popped = false;
        if(g[i][j] == ')'){
            if(st.empty()) return false;
            st.pop();
            popped = true;
        }
        else{
            st.push('(');
        }

        bool ok;
        if(i == g.size()-1 && j == g[0].size()-1){
            ok = st.empty();
        }
        else{
            ok = f(g,i,j+1,st,dp) || f(g,i+1,j,st,dp);       // NEW: pass dp
        }

        if(popped) st.push('(');
        else st.pop();

        return dp[i][j][sz] = ok;                             // NEW: save result
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if((m + n - 1) % 2 != 0) return false;
        stack<char> st;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m + n, -1)));  // NEW
        return f(grid,0,0,st,dp);                             // NEW: pass dp
    }
};