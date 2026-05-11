class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        unordered_map<int,int> mpp;
        sort(ans.begin(),ans.end());
        int rank = 0;
        int prev;
        for(int i=0;i<arr.size();i++){
            if(i != 0 && prev == ans[i]){
                mpp[ans[i]] = rank;
                continue;
            }
            else{
                rank++;
            }
            prev = ans[i];
            mpp[ans[i]] = rank;
        }
        for(int i=0;i<ans.size();i++){
            ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};