class Solution {
  public:
    int Fibonacci(int n) {
        int x = 1, x_1 = 1, x_2 = 1;
        if (n == 1 || n == 2)return 1;
        for (int i = 3; i <= n; i++) {
            int temp = x;
            x = x_1 + x;
            x_2 = x_1;
            x_1 = temp;
        }//1 1 2 3 5 8
        return x;
    }
};