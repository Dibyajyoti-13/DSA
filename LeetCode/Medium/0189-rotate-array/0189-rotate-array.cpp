class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        for(int i = 0; i < gcd(n, k); i++){
            int curr = i;
            int prev = nums[i];

            do{
                int next = (curr + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
            }while(i != curr);
        }
    }
};