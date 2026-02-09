class Solution {
public:
    /*
    Goal:
    Find median of two sorted arrays in O(log(m+n)) WITHOUT merging.

    Hint:
    the question mentions complexity in log and no merging -> binary search
    Strategy:
    Instead of merging, we "cut" both arrays so that:
    - Left half contains exactly half of total elements.
    - Every element on left <= every element on right.

    Once that condition holds:
    - Odd total -> median = max(left side)
    - Even total -> median = average(max(left), min(right))
    */

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search the smaller array.
        // Prevents index overflow and keeps complexity minimal.
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while(low <= high){

            // i = how many elements taken from nums1 into left half
            int i = (low + high) / 2;

            // Remaining elements must come from nums2
            // to make total left side exactly half.
            int j = (m + n + 1)/2 - i;

            // Values just around the cut.
            // If cut touches boundary, use +/- infinity
            // so comparisons still work cleanly.
            int n1_left  = (i==0) ? INT_MIN : nums1[i-1];
            int n1_right = (i==m) ? INT_MAX : nums1[i];
            int n2_left  = (j==0) ? INT_MIN : nums2[j-1];
            int n2_right = (j==n) ? INT_MAX : nums2[j];

            // Correct partition condition:
            // largest left <= smallest right
            if(n1_left <= n2_right && n2_left <= n1_right){

                // Odd total length -> left side has median
                if((m+n)%2)
                    return max(n1_left, n2_left);

                // Even total -> average of two middle values
                return (max(n1_left,n2_left)
                       + min(n1_right,n2_right)) / 2.0;
            }

            // Too many elements taken from nums1,
            // move cut left.
            else if(n1_left > n2_right)
                high = i - 1;

            // Too few taken from nums1,
            // move cut right.
            else
                low = i + 1;
        }
        
        return 0; // logically unreachable
    }
};
