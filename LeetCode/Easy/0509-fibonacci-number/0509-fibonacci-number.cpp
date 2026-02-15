class Solution {
public:
    int fib(int x) {
        if(x == 0) return 0;
        if(x < 3) return 1;
        return fib(x - 1) + fib(x - 2);
    }
};