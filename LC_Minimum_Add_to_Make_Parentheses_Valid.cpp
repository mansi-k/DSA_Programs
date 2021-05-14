// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
// Logic : Use a stack. If the current string char is ')' and stack top has '(', then pop 1 from stack else push the char into stack. After parsing the string, return the size of the stack.
public:
    int minAddToMakeValid(string s) {
        if(s.length() <= 0)
            return s.length();
        stack<char> stk;
        stk.push(s[0]);
        for(int i=1;i<s.length();i++) {
            if(stk.size()>0 && stk.top()=='(' && s[i]==')') {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }
        return stk.size();
    }
};
