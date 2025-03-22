class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        std::unordered_set<int> visited;

        // Build a map for each node with its neighbours
        std::unordered_map<int, std::vector<int>> neighbours;
        for(std::vector<int> edge : edges) {
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }

        int components = 0;

        for(int i=0;i<n;i++) {
            if(visited.count(i)) {
                continue;
            }

            std::queue<int> to_search;
            to_search.push(i);
            visited.insert(i);

            std::unordered_set<int> component_nodes;
            int edge_count = 0;

            while (!to_search.empty()) {
                int visiting = to_search.front();
                to_search.pop();
                component_nodes.insert(visiting);

                for (int neighbor : neighbours[visiting]) {
                    edge_count++;
                    if (!visited.count(neighbor)) {
                        to_search.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }

            // If all nodes in the component are connected to eachother, then
            // the number of edges will be (nodes * (nodes - 1)) / 2
            int node_count = component_nodes.size();
            if (edge_count / 2 == (node_count * (node_count - 1)) / 2) {
                components++;
            }
        }

        return components;
    }
};
