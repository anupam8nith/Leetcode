class Solution {
public:
    // Function to calculate the score of a single word
    int scoreCalculator(string word, vector<int>& count, vector<int>& scores) 
    {
        vector<int> charCount(26, 0);
        int score = 0;

        // Calculate the score of the word if it can be formed
        for (char ch : word) {
            int pos = ch - 'a';
            charCount[pos]++;
            if (charCount[pos] <= count[pos]) {
                score += scores[pos];
            } else {
                return 0; // Word can't be formed
            }
        }
        return score;
    }

    // Function to calculate the maximum score of words that can be formed
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for (char ch : letters) {
            count[ch - 'a']++;
        }
        return maxSScoreHelper(0, words, score, count);
    }

    // Helper function to recursively calculate the maximum score
    int maxSScoreHelper(int index, vector<string>& words, vector<int>& score, vector<int>& count) 
    {
        if (index == words.size()) return 0; // Base case: no more words to consider

        // Calculate the maximum score without including the current word
        int maxScore = maxSScoreHelper(index + 1, words, score, count);

        // Calculate the score if the current word is included
        int include = scoreCalculator(words[index], count, score);
        if (include > 0) {
            vector<int> tempCount = count; // Copying the array
            for (char ch : words[index]) {
                tempCount[ch - 'a']--;
            }
            // Update maxScore by including the current word and recursively calculate the score for the remaining words
            maxScore = max(maxScore, include + maxSScoreHelper(index + 1, words, score, tempCount));
        }
        return maxScore;
    }
};