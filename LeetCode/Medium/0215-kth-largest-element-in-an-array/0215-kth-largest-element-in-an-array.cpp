class Solution {
public:
    void threeWayPartition(vector<int>& nums, int left, int right,
                           int& lt, int& gt) {
        int pivot = nums[left];
        lt = left;
        gt = right;
        int i = left;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i++], nums[lt++]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt--]);
            } else {
                i++;
            }
        }
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left > right) return -1;

        int lt, gt;
        threeWayPartition(nums, left, right, lt, gt);

        if (k >= lt && k <= gt) return nums[k];
        else if (k < lt) return quickSelect(nums, left, lt - 1, k);
        else return quickSelect(nums, gt + 1, right, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
};
