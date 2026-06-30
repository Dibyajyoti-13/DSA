class Solution {
    public int maxArea(int[] height) {
        int max_cap = 0;
        int left = 0;
        int right = height.length - 1;

        while(left < right){
            max_cap = Math.max(max_cap, (right - left) * Math.min(height[left], height[right]));
            if(height[left] > height[right]) right--;
            else left++;
        }
        return max_cap;
    }
}