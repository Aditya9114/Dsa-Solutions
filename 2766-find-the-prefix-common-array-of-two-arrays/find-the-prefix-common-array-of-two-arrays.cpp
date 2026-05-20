class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mppB;
        vector<int> ans(A.size(),0);
        for(int i=0;i<A.size();i++){
            int count = 0;
            mppB[B[i]] = 1;
            for(int j=0;j<=i;j++){
                if(mppB[A[j]] == 1){
                    count ++;
                }
                ans[i] = count;
            }
        }
        return ans;
    }
};