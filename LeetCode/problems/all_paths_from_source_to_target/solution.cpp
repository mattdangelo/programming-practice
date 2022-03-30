class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& res, vector<int>& path, int cur) {
        path.push_back(cur);
        if (cur == g.size() - 1) {
            res.push_back(path);
        }
        else {
          for (int i: g[cur]) {
              dfs(g, res, path, i);  
          }
        } 
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, path, 0);
        return paths;
    }
};