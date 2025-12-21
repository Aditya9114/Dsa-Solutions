class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       priority_queue<pair<int,int>> pq;

        for(int i=0;i<boxTypes.size();i++){
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }
        int size = truckSize;
        int res = 0;
        while(!pq.empty() && size > 0){
            int boxes = pq.top().second;
            int units = pq.top().first;
            pq.pop();
            size = size-boxes;
            if(size >= 0){
                res+=(boxes * units);
            }
            else{
                size += boxes;
                res+=size*units;
                break;
            }
        }
        return res;
    }
};