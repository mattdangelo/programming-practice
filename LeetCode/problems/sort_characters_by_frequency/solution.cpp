class Solution {
struct counter_value {
    int count;
    char value;

public:
    counter_value(char value) {
        this->value = value;
        this->count = 1;
    }

    bool operator<(const counter_value& y) const
    {
        return(this->count < y.count);
    }

};

public:
    string frequencySort(string s) {
        std::unordered_map<char, int> index;
        std::vector<counter_value> counts;

        for(char c : s) {
            if(index.count(c)) {
                counts[index[c]].count = counts[index[c]].count + 1;
            }
            else {
                counts.emplace_back(counter_value(c));
                index[c] = counts.size() - 1;
            }
        }

        std::sort(counts.rbegin(), counts.rend());

        std::string result = "";

        for(counter_value c : counts) {
            for(int i=0;i<c.count;i++) {
                result += c.value;
            }
        }

        return result;
    }
};