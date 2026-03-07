class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k % n;

        for(int i = 0; i < gcd(n, k); i++){
            int curr = i;
            int val = nums[i];

            while(true){
                int next = (curr + k) % n;

                if(next == i) break;

                nums[curr] = nums[next];
                curr = next;
            }
            nums[curr] = val;
        }
    }
};