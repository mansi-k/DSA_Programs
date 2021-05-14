// https://leetcode.com/problems/partition-labels/

class Solution {
// Logic : For each char in the string store the greatest index at which it is repeated. Parse the string again and keep track of the max repetition index. If it equals to the current postion then 1 partition finishes at there.
public:
    vector<int> partitionLabels(string S) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        vector<int> pos(26);
        vector<int> parts;
        for(int i=0;i<S.length();i++) {
            pos[S[i]-'a'] = i;
        }
        int maxpos = 0;
        int c=1;
        for(int i=0;i<S.length();i++,c++) {
            int x = S[i]-'a';
            // cout << S[i] << pos[x] << endl;
            if(pos[x] > maxpos) {
                maxpos = pos[x];
            }
            if(pos[x]==maxpos && pos[x]==i) {
                parts.push_back(c);
                c=0;
            }
        }
        return parts;
    }
};
