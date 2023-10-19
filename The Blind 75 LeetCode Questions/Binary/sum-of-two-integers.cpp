class Solution {
public:
    int getSum(int a, int b) {
        do{
        int sum = a^b;
        int carry = (a&b) << 1;
        a=sum;
        b=carry;
        }while(b!=0);
        return a;
    }
};
