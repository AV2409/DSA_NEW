class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        st.insert(wordList.begin(),wordList.end());

        if(st.count(beginWord)) st.erase(beginWord);
        if(!st.count(endWord)) return 0;

        queue<string>q;
        q.push(beginWord);
        int ans=1;
        while(!q.empty()){
            int ss=q.size();
            for(int i=0;i<ss;i++){
                string word=q.front();
                q.pop();

                if(word==endWord) return ans; 

                int n=word.size();
                for(int j=0;j<n;j++){
                    char ch=word[j];
                    for(char c='a';c<='z';c++){
                        if(ch==c) continue;

                        word[j]=c;
                        if(st.count(word)){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[j]=ch;
                }


            }
            ans++;
        }
        return 0;
    }
};