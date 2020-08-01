class Solution {
public:
    int findComplement(int num) {
        int bitCount = log2(num)+1;
        for(int i=0;i<bitCount ; i++){
            num = num ^ (1<<i);
        }
        return  num;
        // return setBits-num;
    }
};
