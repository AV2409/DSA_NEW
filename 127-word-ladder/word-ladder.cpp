class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        st.insert(wordList.begin(),wordList.end());
        st.erase(beginWord);
        queue<string>q;
        q.push(beginWord);
        int n=beginWord.size();
        int dist=1;
        while(!q.empty()){
            int ss=q.size();

            for(int i=0;i<ss;i++){
                string word=q.front();
                q.pop();
                if(word==endWord) return dist;
                
                for(int i=0;i<n;i++){
                    char ch=word[i];
                    for(char c='a';c<='z';c++){
                        if(c==ch) continue;
                        word[i]=c;
                        if(st.count(word)) {
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i]=ch;
                }

            }
            dist++;
        }
        return 0;

    }
};