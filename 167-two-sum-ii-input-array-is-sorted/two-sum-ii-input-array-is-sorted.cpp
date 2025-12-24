class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<numbers.size();i++){
            mpp[numbers[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<numbers.size();i++){
            int num = numbers[i];
            int rem = target - num;
            if(mpp.find(rem) != mpp.end()){
                auto it = mpp.find(rem);
                ans.push_back(i+1);
                ans.push_back(it->second + 1);
                break;
            }
        }
        return ans;
    }
};