class Solution {
public:
    std::unordered_map<std::string, std::string> url_map;
    hash<std::string> hasher;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        std::string hash = std::to_string(hasher(longUrl));
        url_map[hash] = longUrl;
        return hash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return url_map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));