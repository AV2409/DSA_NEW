class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int index=0;
        int n=chars.size();

        while(i<n){
            int j=i;

            while(j<n && chars[i]==chars[j]) j++;
            //after completion either at new char or end of array

            //storing old char
            chars[index++]=chars[i];

            int count=j-i;

            //storing count if >1
            if(count>1){
                string temp=to_string(count);
                for(char ch : temp){
                    chars[index++]=ch;
                }
            }

            i=j;
        }
        return index;
    }
};