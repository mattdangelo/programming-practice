class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        std::unordered_map<std::string, std::vector<std::string>> content_to_paths;
        
        for(std::string path : paths) {
            stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' ')) {
                string fileName = root + '/' + s.substr(0, s.find('('));
                string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                content_to_paths[fileContent].push_back(fileName);
            }
        }
        
        std::vector<std::vector<std::string>> res;
        
        for(std::pair<std::string, std::vector<std::string>> p : content_to_paths) {
            if(p.second.size() > 1) {
                res.push_back(p.second);
            }
        }
        
        return res;
    }
};
