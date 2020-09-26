#include<bits/stdc++.h>
using namespace std;
int main(){
    int num = 5;
         int bitCount = log2(num);
         cout<<bitCount<<" ";
        for(int i=0;i<=bitCount ; i++){
            num = num ^ (1<<i);
        }
        cout<<num;
        return 0;
        
}