// https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution {
// Logic : Use recursion to calculate power and store the pre-calculated powers (DP). Here mapis used to store only the required powers, but an array of length 1000 can be used to store all powers from 1 to 1000.
public:
    unordered_map<int,int> power_table; // unordered as hashing can be faster
    vector<pair<int,int>> powers; // to store powers from lo to hi
    
    int getKth(int lo, int hi, int k) {
        for(int i=lo;i<=hi;i++) {
            int p = getPower(i);
            powers.push_back(make_pair(p,i));
        }
        sort(powers.begin(),powers.end());
        return powers[k-1].second;
    }
    
    int getPower(int num) {
        if(num==1) {
            return 1;
        }
        int temp=0;
        int x=0;
        if(num%2 == 0) {
            x = num/2;
            if(power_table.find(x)!=power_table.end())
                temp = power_table[x];
            else
                temp = getPower(x);
        }
        else {
            x = num*3+1;
            if(power_table.find(x)!=power_table.end())
                temp = power_table[x];
            else
                temp = getPower(num*3+1);
        }
        power_table[num] = temp+1;
        return temp+1;
    }
};
