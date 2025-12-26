class Solution {
public:
    int bestClosingTime(string customers) {
        int prefix = 0;
        int suffix = 0;
        int n = customers.size();
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y'){
                suffix++;
            }
        }
        int totalPen = suffix + prefix;
        int prevPenalty = totalPen;
        int closingTime = 0;
        for(int i=1;i<customers.size();i++){
            if(customers[i-1] == 'Y')suffix--;
            else prefix++;
            if(prevPenalty > (suffix+prefix)){
                closingTime = i;
                prevPenalty = suffix+prefix;
            }
        }
        int Prefix = 0;
        for(int i=0;i<n;i++){
            if(customers[i] == 'N'){
                Prefix++;
            }
        }
        if(prevPenalty > Prefix){
            closingTime = n;
        }
        return closingTime;
    }
};