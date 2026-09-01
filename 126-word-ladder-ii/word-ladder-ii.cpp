class Solution {
public:
    unordered_map<string,vector<string>>par;
    vector<vector<string>>ans;
    vector<string>list;
    void buildAns(string &word){
        if(par[word].size()==0){
            ans.push_back(list);
            return;
        }

        for(string x:par[word]){
            list.push_back(x);
            buildAns(x);
            list.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        st.insert(wordList.begin(),wordList.end());

        if(!st.count(endWord)) return ans;
        st.erase(beginWord);
        int n=beginWord.size();

        bool found=false;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            int ss=q.size();
            set<string>temp;
            
            for(int i=0;i<ss;i++){
                string word=q.front();
                q.pop();
                string parent=word;
                if(word==endWord) {
                    found=true;
                    break; 
                }
                
                for(int j=0;j<n;j++){
                    char og=word[j];

                    for(char c='a';c<='z';c++){
                        if(og==c) continue;
                        word[j]=c;
                        if(st.count(word)){
                            if (!temp.count(word)) {
                                q.push(word);
                                temp.insert(word);
                            }
                            par[word].push_back(parent);
                        }
                        word[j]=og;
                        
                    }
                }

            }
            for(auto x:temp){
                st.erase(x);
            }
            if(found) break;

        }
        if(!found) return ans;
        list.push_back(endWord);
        buildAns(endWord);
        for(auto &l:ans){
            reverse(l.begin(),l.end());
        }
        return ans;
    }
};