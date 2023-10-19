class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long count = 31, ans=0;
        while(count >= 0){
            int var = n%2;
            n/=2;
            ans += var * pow(2,count);
            count--;
        }
        return ans;
    }
};
