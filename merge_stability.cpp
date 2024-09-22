#include<bits/stdc++.h>
using namespace std;
// to check the stability of merge mergesort
// and it is proved by below code that mergesort
// is the stable sorting algorithm 
// means it dont change the relative order of same element

// input : 1 2 3 1 2
// output: (1,0) (1,3) (2,1) (2,4) (3,2)

void merge(int low,int mid,int high,vector<pair<int,int>>&v){
    vector<pair<int,int>>temp;
    int left=low, right=mid+1;
    while(left<=mid && right<=high){
        if(v[left].first <= v[right].first){
            temp.push_back(v[left]);
            left++;
        }else{
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        v[i]=temp[i-low];  // Copy back the original pairs
    }
}

void mergesort(int low,int high,vector<pair<int,int>>&v){
    if(low >= high){
        return ;
    }
    int mid=low+(high-low)/2;
    mergesort(low,mid,v);
    mergesort(mid+1,high,v);
    merge(low,mid,high,v);
}
void solve(){
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v[i]={a,i};
    }
    mergesort(0,n-1,v);
    for(auto i:v){
        cout<<i.first<<","<<i.second<<"   ";
    }
}
int main(){
    solve();
    return 0;
}