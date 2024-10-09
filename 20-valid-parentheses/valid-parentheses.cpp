class Solution {
public:
    bool isValid(string s) {
        stack<int> s1;
    int n = s.length();
    int i = 0;
    if ((s[0] == ')') || (s[0] == '}') || (s[0] == ']')){
          return 0;
      }
    while (i < n) {
      
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            s1.push(s[i]);
        }
        else {
            if (s1.empty()) {
                return false; // If there's no opening bracket for a closing one
            }
            char top = s1.top();
            if ((s[i] == ')' && top == '(') ||
                (s[i] == '}' && top == '{') ||
                (s[i] == ']' && top == '[')) {
                s1.pop(); // Matching pair found, pop the stack
            } else {
                return false; // Mismatched bracket
            }
        }

        i++;
    }
    if (s1.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
    }
};