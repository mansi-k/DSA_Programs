// https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
// Logic : Push the current paranthesis into the stack if it equals to stack.top (stack not empty) and append it to the result. If current paranthesis is not equal to stack.top then pop from stack and append to the string only if stack is not empty.
public:
    string removeOuterParentheses(string S) {
        if(S.length() <= 1)
            return S;
        stack<char> stk;
        stk.push(S[0]);
        string res="";
        for(int i=1;i<S.length();i++) {
            if(stk.empty() || stk.top()==S[i]) {
                stk.push(S[i]);
                if(stk.size() > 1)
                    res += S[i];
            }
            else {
                stk.pop();
                if(!stk.empty())
                    res += S[i];
            }            
        }
        return res;
    }
};
