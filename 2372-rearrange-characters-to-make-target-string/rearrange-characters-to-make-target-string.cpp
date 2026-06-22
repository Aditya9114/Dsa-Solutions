class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> targetCount;
        unordered_map<char, int> sCount;
        for (int i = 0; i < s.size(); i++) {
            sCount[s[i]]++;
        }
        for (int i = 0; i < target.size(); i++) {
            targetCount[target[i]]++;
        }
        int count = 0;
        vector<int> ans;
        int flag = 0;
        for (auto x : targetCount) {
            int inter = sCount[x.first] / x.second;
            if (inter == 0) {
                flag = 1;
                break;
            }
            ans.push_back(inter);
        }
        if(flag == 1)return 0;
        int finalans = *min_element(ans.begin(), ans.end());
        return finalans;
    }
};