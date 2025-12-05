class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;

        vector<int> nge(n,0);

        for(int i=n-1;i>=0;i--){
            while((!st.empty()) && temp[i]>=temp[st.top()]){
                st.pop();
            } 
            if((!st.empty()) && temp[i]<temp[st.top()]){
                nge[i]=st.top();
            }
            if(st.empty()){
                nge[i]=0;
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(nge[i]==0)continue;
            nge[i]=nge[i]-i;
        }
        return nge;
    }
};