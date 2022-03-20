class Solution {
private:
    int colour;
    int newColour;
    std::set<uint64_t> visited;
    
    uint64_t genKey(int sr, int sc) {
        uint64_t key = sr;
        key = key << 32;
        key = key | sc;
        return key;
    }

public:
    void recFloodFill(vector<vector<int>>& image, int sr, int sc) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || visited.count(genKey(sr, sc)) > 0 || image[sr][sc] != colour) {
            return;
        }

        visited.insert(genKey(sr, sc));

        recFloodFill(image, sr + 1, sc);
        recFloodFill(image, sr - 1, sc);
        recFloodFill(image, sr, sc + 1);
        recFloodFill(image, sr, sc - 1);

        image[sr][sc] = newColour;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        colour = image[sr][sc];
        newColour = newColor;
        if(colour == newColor) {
            return image;
        }

        recFloodFill(image, sr, sc);
        return image;
    }
};
