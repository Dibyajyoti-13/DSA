class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<bool> prime(n + 1, true);
        for(int p = 2; p*p <= n; p++){
            if(prime[p]){
                for(int i = p * p; i <= n; i += p){
                    prime[i] = false;
                }
            }
        }
        
        vector<int> result;
        for(int i = 2; i <= n; i++){
            if(prime[i]) result.push_back(i);
        }
        return result;
    }
};