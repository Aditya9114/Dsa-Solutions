class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int loopSize = size1 + size2;
        int firstPtr = 0, secondPtr = 0;
        for (int i = 0; i < loopSize; i++) {
            if (nums1[firstPtr] == nums2[secondPtr])
                return nums1[firstPtr];
            else if (nums1[firstPtr] < nums2[secondPtr] && firstPtr < size1-1) {
                firstPtr++;
            } else {
                if(secondPtr < size2-1)secondPtr++;
            }
        }
        return -1;
    }
};