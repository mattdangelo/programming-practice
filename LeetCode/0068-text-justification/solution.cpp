class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::vector<std::string>> lines;

        int count = 0;
        std::vector<std::string> line;

        for(int i=0;i<words.size();i++) {
            bool first_word = line.empty();
            int count_if_added = count + (first_word ? words[i].length() : words[i].length() + 1);

            // Check if we can add another word
            if(count_if_added > maxWidth) {

                // If not, push what we have and backtrack a word
                lines.push_back(line);
                line.clear();
                count = 0;
                i--;
            }
            else {
                line.push_back(words[i]);
                count += (first_word ? words[i].length() : words[i].length() + 1);
            }
        }
        
        if(line.size() > 0) {
           lines.push_back(line); 
        }
        
        std::vector<std::string> result;
        result.reserve(lines.size());

        for(int i=0;i<lines.size();i++) {
            int gap_count = lines[i].size() - 1;
            std::string line_s = "";

            if((i == lines.size() - 1) || gap_count == 0) {
                // Special handling for left justified lines
                
                for(int j=0;j<lines[i].size();j++) {
                    line_s += lines[i][j];
                    if(j == lines[i].size() - 1)
                        continue;

                    line_s += " ";
                }
                
                // Pad the end with spaces until we hit max width
                while(line_s.length() < maxWidth) {
                    line_s += " ";
                }
            }
            else {
                count = 0;
                for(std::string s : lines[i]) {
                    count += s.length();
                }

                std::string gaps[gap_count];

                // Add in the spaces between words from left to right until we hit max width
                int ptr = 0;
                while(count < maxWidth) {
                    gaps[ptr] += " ";
                    ptr = (ptr + 1) % gap_count;
                    count++;
                }

                // Construct string
                for(int j=0;j<lines[i].size();j++) {
                    line_s += lines[i][j];
                    if(j >= gap_count)
                        continue;

                    line_s += gaps[j];
                }
            }
            
            result.push_back(line_s);
        }
        
        return result;
    }
};
