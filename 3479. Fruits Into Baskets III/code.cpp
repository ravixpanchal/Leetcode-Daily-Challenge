class Solution {
public:
vector<int>segtree;
void build(vector<int>&baskets,int i,int l,int r){
    if(l==r){
        segtree[i]=baskets[l];
        return;
    }
    int mid=(l+r)/2;
    build(baskets,2*i+1,l,mid);
    build(baskets,2*i+2,mid+1,r);
    segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
}

bool query(int i,int l,int r,int val){
    if(segtree[i]<val){
        return false;
    }

    if(l==r){
    segtree[i]=-1; 
    return true;
    } 

    int mid=(l+r)/2;
    bool placed=false;
    if(segtree[2*i+1]>=val) placed=query(2*i+1,l,mid,val);
    else placed=query(2*i+2,mid+1,r,val);
    segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
    return placed;

}
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        segtree.resize(4*n,-1);
        build(baskets,0,0,n-1);
        int ans=0;
        for(auto x: fruits){
            if(query(0,0,n-1,x)==false)ans++;
        }
        return ans;
    }
};