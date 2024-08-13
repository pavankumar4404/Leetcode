class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), k = words.size(), wordLength = words[0].length(),
            totalLength = wordLength * k;

        unordered_map<string, int> wordCount;
        for (string word : words)
            ++wordCount[word];

        vector<int> res;
        for (int i = 0; i < wordLength; ++i)
            slidingWindow(i, s, n, wordCount, k, wordLength, totalLength, res);

        return res;
    }
    void slidingWindow(int l, string& s, int n,
                       unordered_map<string, int>& wordCount, int k,
                       int wordLength, int totalLength, vector<int>& res) {

        unordered_map<string, int> wordsFound;
        int wordsUsed = 0;
        bool excessWord = false;

        for (int r = l; r <= n - wordLength; r += wordLength) {

            string sub = s.substr(r, wordLength);
            if (wordCount.find(sub) == wordCount.end()) {
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                l = r + wordLength;
            } 
            else {
                while (r - l == totalLength || excessWord) {
                    string leftmostWord = s.substr(l, wordLength);
                    l += wordLength;
                    --wordsFound[leftmostWord];

                    if (wordsFound[leftmostWord] >= wordCount[leftmostWord])
                        excessWord = false;
                    else
                        --wordsUsed;
                }

                ++wordsFound[sub];

                if (wordsFound[sub] <= wordCount[sub])
                    ++wordsUsed;
                else
                    excessWord = true;

                if (wordsUsed == k && !excessWord) {
                    res.push_back(l);
                }
            }
        }
    }
};