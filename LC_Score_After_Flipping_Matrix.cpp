// https://leetcode.com/problems/score-after-flipping-matrix/

class Solution {
public:
int matrixScore(vector<vector<int>>& A) {

    int r = A.size();
    int c = A[0].size();
    vector<int>col(c);
    
    for(int i = 0; i < r; i++){
        bool flag = false;
        for(int j = 0; j < c; j++){ 
            if((j == 0 && A[i][j] == 0) || flag){  // flip if MSB is 0
                A[i][j] = !A[i][j];
                flag = true;
            }
            if(A[i][j] == 1){ // store number of 1s in each column after flipping
                col[j] += 1;
            }
        }
    }
    
    // dont actually flip columns, instead just check the following
    int score = (1<<(c-1))*r; // r bcz MSBs of all rows have been flipped to 1 (1000(8) * 3 here)
    cout << (1<<(c-1)) << " " << r << endl;
    for(int j = 1; j < c; j++){
        cout << score << endl;
        score += (1<<(c-j-1))*max(col[j], r-col[j]); // for each column check if no. of 1s in all rows is more or no. of 0s in all rows is more (ie. if 0s is more than the column will be flipped)
    }
    return score;
}
};
