// https://leetcode.com/problems/generate-parentheses/

class Solution {
// Logic : Check balance conditions while genrating paranthesis in recursive function 
public:
    vector<string> combos;
    
    vector<string> generateParenthesis(int n) {
        get_combos("(", n, 1, 0);
        return combos;
    }
    
    void get_combos(string pstr, int n, int nopen, int nclose) {
        if(pstr.length()==2*n) {
            if(nopen==n && nclose==n) {
                combos.push_back(pstr);
                return;
            }
            return;
        } 
        string curstr = pstr;
        if(nclose < nopen) {
            curstr += ')';
            get_combos(curstr, n, nopen, nclose+1);
        }
        curstr = pstr;
        if(nopen < n) {
            curstr += '(';
            get_combos(curstr, n, nopen+1, nclose);
        }
    }
};
