class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changeCount5 = 0;
        int changeCount10 = 0;

        for (int i = 0; i < bills.size(); i++) {

            if (bills[i] == 5) {
                changeCount5++;
            }

            else if (bills[i] == 10) {
                if (changeCount5 == 0) return false;
                changeCount5--;
                changeCount10++;
            }

            else { 
                if (changeCount10 > 0 && changeCount5 > 0) {
                    changeCount10--;
                    changeCount5--;
                }
                else if (changeCount5 >= 3) {
                    changeCount5 -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
