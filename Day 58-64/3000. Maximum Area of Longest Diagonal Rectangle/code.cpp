class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiaSqr=0, maxArea=0;\

        for(auto i: dimensions){
        int l=i[0], w=i[1];
        double diaSqr=l*l+w*w;
        int area=l*w;
        if(diaSqr>maxDiaSqr){
            maxDiaSqr=diaSqr;
            maxArea=area;
        }else if(diaSqr==maxDiaSqr){
            maxArea=max(maxArea,area);

        }
    }
    return maxArea;    
    }
};