// Recursion tree with each level corresponding to the letters of a digit. Apply DFS on the tree.

class Solution {
public:
    vector<string> ans;

    void dfs(string digits,string temp,int idx,vector<string> v){
        // cout << temp << endl;
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }

        string val=v[digits[idx]-'0'];
        for(int i=0;i<val.length();i++){
            dfs(digits,temp+val[i],idx+1,v);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return ans;
        }
        string temp;
        vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        dfs(digits,temp,0,v);
        return ans;
    }
};
