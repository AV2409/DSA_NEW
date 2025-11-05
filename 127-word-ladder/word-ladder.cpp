class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st;
        int ss = beginWord.size();
        for (auto str : wordList) {
            st.insert(str);
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       greater<pair<int, string>>>
            q;

        q.push({1, beginWord});

        while (!q.empty()) {
            auto tt = q.top();
            q.pop();

            string word = tt.second;
            if (word == endWord)
                return tt.first;
            for (int i = 0; i < ss; i++) {
                char temp = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        q.push({tt.first + 1, word});
                        st.erase(word);
                    }
                }
                word[i] = temp;
            }
        }
        return 0;
    }
};