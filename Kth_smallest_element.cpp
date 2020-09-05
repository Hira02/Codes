#include<bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int>& arr, int n, int k){
    priority_queue<int, vector<int>> pq;
    for(int i = 0 ; i < n ; i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i = 0 ; i < n ; i++){
            int val;
            cin>>val;
            arr.push_back(val);
        }
        int k;
        cin>>k;
        cout<<kthSmallest(arr, n, k)<<"\n";
    }
}