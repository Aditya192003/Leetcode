class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> wordCount;
        string word;
        int maxCount = 0;
        string result;

        // Convert to lowercase and replace punctuation with space
        for (char &c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }

        // Use stringstream to split words
        stringstream ss(paragraph);
        while (ss >> word) {
            if (bannedSet.find(word) == bannedSet.end()) {
                wordCount[word]++;
                if (wordCount[word] > maxCount) {
                    maxCount = wordCount[word];
                    result = word;
                }
            }
        }

        return result;
    }
};