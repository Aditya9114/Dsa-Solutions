class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<string,int> mpp;
        for(int i=0;i<arr1.size();i++){
            string s = to_string(arr1[i]);
            for(int j=0;j<s.size();j++){
                string key = s.substr(0,j+1);
                mpp[key] = 1;
            }
        }
        
        for(int i=0;i<arr2.size();i++){
            string s = to_string(arr2[i]);
            int count = 0;
            for(int j=0;j<s.size();j++){
                string value = s.substr(0,j+1);
                if(mpp[value] == 1)count++;
                else break;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};