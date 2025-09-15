#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>>findDifference(vector<int>&nums1,vector<int>&nums2){
    set<int>s1(nums1.begin(),nums1.end());
    set<int>s2(nums2.begin(),nums2.end());
    vector<int>l1,l2;

    for(auto i:s1){
        if(s2.find(i)==s2.end()){
            l1.push_back(i);
        }
    }

    
    for(auto i:s2){
        if(s1.find(i)==s1.end()){
            l2.push_back(i);
        }
    }

    return {l1,l2};



}

int main(){
    vector<int>nums1={1,2,3,3};
    vector<int>nums2={1,1,2,2};
    vector<vector<int>>ans=findDifference(nums1,nums2);

    for(auto x: ans){
        cout<<"[";
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
    return 0;
}