// https://leetcode.com/problems/maximum-units-on-a-truck/

bool compareVectors(vector<int>& v1, vector<int>& v2) {
    return (v1[1] > v2[1]);
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int full=0, tmp=0, units=0;
        sort(boxTypes.begin(),boxTypes.end(),compareVectors); // desc sort wrt unitsperbox
        for(int i=0;i<boxTypes.size() && full<truckSize;i++) {
            tmp = full + boxTypes[i][0];
            if(tmp <= truckSize) {
                full = tmp;
                units += boxTypes[i][0] * boxTypes[i][1];
            }
            else {
                tmp = truckSize - full;
                full = truckSize;
                units += tmp * boxTypes[i][1];
            }
        }
        return units;
    }
};
