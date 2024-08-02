class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> queriesCount, wordsCount, answer;
        
        // Calculate f(s) for each string s in queries and words
        for (string s : queries) {
            queriesCount.push_back(f(s));
        }
        for (string s : words) {
            wordsCount.push_back(f(s));
        }
        
        // Sort wordsCount in ascending order
        sort(wordsCount.begin(), wordsCount.end());
        
        // Count the number of words with f(w) > f(queries[i]) for each query
        for (int i = 0; i < queriesCount.size(); i++) {
            int count = wordsCount.end() - upper_bound(wordsCount.begin(), wordsCount.end(), queriesCount[i]);
            answer.push_back(count);
        }
        
        return answer;
    }
    
private:
    int f(string s) {
        char smallest = 'z';
        int count = 0;
        
        // Find the lexicographically smallest character and its frequency
        for (char c : s) {
            if (c < smallest) {
                smallest = c;
                count = 1;
            } else if (c == smallest) {
                count++;
            }
        }
        
        return count;
    }
};