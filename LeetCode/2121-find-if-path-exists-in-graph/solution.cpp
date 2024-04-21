class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) {
            return true;
        }

        std::vector<std::vector<int>> connections(n);
        for(std::vector<int> edge : edges) {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }

        // Start the source
        std::stack<int> stack;
        for(int i : connections[source]) {
            stack.push(i);
        }

        // Visit source
        connections[source] = {};

        while(!stack.empty()) {
            int visiting = stack.top();
            stack.pop();

            if(visiting == destination) {
                return true;
            }

            for(int i : connections[visiting]) {
                if(connections[i].empty()) {
                    continue;
                }

                stack.push(i);
            }

            // Visited this node
            connections[visiting] = {};
        }

        return false;
    }
};
