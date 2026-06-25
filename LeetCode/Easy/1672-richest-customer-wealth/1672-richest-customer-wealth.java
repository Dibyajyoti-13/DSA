class Solution {
    public int maximumWealth(int[][] accounts) {
        int max_wealth = 0;

        for(int i = 0; i < accounts.length; i++){
            int wealth = 0;
            for(int j = 0; j < accounts[0].length; j++){
                wealth += accounts[i][j];
            }
            max_wealth = Math.max(max_wealth, wealth);
        }
        return max_wealth;
    }
}