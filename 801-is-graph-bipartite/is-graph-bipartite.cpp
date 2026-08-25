class Solution {
public:

    bool bfs(int start, vector<vector<int>> &graph, vector<int> visited){
        visited[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(visited[it] == -1){
                    visited[it] = !visited[node];
                    q.push(it);
                }
                else if(visited[it] == visited[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),-1);
        for(int i=0; i<graph.size(); i++){
            if(visited[i] == -1){
                if(bfs(i,graph,visited) == false)return false;
            }
        }
        return true;
    }
};