class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
           vector<string> words1 = split(sentence1, ' ');
        vector<string> words2 = split(sentence2, ' ');

        int n1 = words1.size();
        int n2 = words2.size();
        
        if (n1 < n2) {
            swap(words1, words2);
            swap(n1, n2);
        }

        int i = 0, j = 0;

        while (i < n2 && words1[i] == words2[i]) {
            i++;
        }

        while (j < n2 && words1[n1 - j - 1] == words2[n2 - j - 1]) {
            j++;
        }

        return i + j >= n2;
    }

private:
    vector<string> split(const string &s, char delimiter) {
        vector<string> result;
        stringstream ss(s);
        string word;

        while (getline(ss, word, delimiter)) {
            result.push_back(word);
        }

        return result;
        
    }
};