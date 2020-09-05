#include <bits/stdc++.h>
using namespace std;
int check(int mat[][]){
    int Row[9][9], Col[9][9], Box[9][9];
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            int val = mat[i][j];
            int k = (i/3)*3+j/3;
            if(Row[i][val] || Col[j][val] || Box[k][val])
            return 0;
            Row[i][val] = Col[j][val] = Box[k][val] =1;
        }
    }
    return 1;
}
int main() {
	//code
    int t;
    cin>>t;
    while(t--){
        int arr[9][9];
        for(int i = 0 ;  i < 9 ; i++){
            for(int j = 0 ; j  < 9 ; j++)
            cin>>arr[i][j];
        }
        cout<<check(arr)<<"\n";

    }
	return 0;
}