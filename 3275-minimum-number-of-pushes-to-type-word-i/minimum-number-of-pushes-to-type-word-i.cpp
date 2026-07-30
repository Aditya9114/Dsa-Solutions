class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alphabet(26,-1);
        int unique = 0;
        for(int i=0; i<word.size();i++){
            if(alphabet[word[i]-'a'] == -1){
                unique++;
                alphabet[word[i]-'a'] = 1;
            }
        }
        if(unique < 9 && word.size() < 9)return unique;
        int result = 0;
        result = 8;
        unique = unique - 8;
        int count = 0;
        int increment = 2;
        while(unique){
            result += increment;
            count++;
            if(count == 8){
                count = 0;
                increment++;
            }
            unique--;
        }
        return result;
    }
};