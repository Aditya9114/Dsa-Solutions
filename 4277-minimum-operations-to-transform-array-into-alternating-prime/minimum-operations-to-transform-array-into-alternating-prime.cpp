class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i <nums.size();i++){
            if(i%2==0 && (!isPrime(nums[i]))){
                int np = nextPrime(nums[i]);
                ans += (np - nums[i]);
            }
            else if(i%2 != 0 && (isPrime(nums[i]))){
                int notPrime = nums[i]+1;
                while(isPrime(notPrime)){
                   notPrime++; 
                }
                ans += (notPrime - nums[i]);
            }
        }
        return ans;
    }
    int nextPrime(int num){
        int ans = num + 1;
        while(true){
            if(isPrime(ans))break;
            ans++;
        }
        return ans;
    }
    bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
    }
};