class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxFruits = 0;
        int sum = 0;
        int left = 0;
        
        for(int right = 0; right < n; right++) {
            sum += fruits[right][1];
            
            // Shrink window while it's not reachable
            while(left <= right && !canReach(fruits[left][0], fruits[right][0], startPos, k)) {
                sum -= fruits[left][1];
                left++;
            }
            
            maxFruits = max(maxFruits, sum);
        }
        
        return maxFruits;
    }
    
private:
    bool canReach(int leftPos, int rightPos, int start, int k) {
        if(rightPos <= start) {
            // All positions are to the left of start
            return start - leftPos <= k;
        }
        if(leftPos >= start) {
            // All positions are to the right of start
            return rightPos - start <= k;
        }
        
        // Positions span across start
        // Strategy 1: go left first, then right
        int leftFirst = 2 * (start - leftPos) + (rightPos - start);
        // Strategy 2: go right first, then left  
        int rightFirst = 2 * (rightPos - start) + (start - leftPos);
        
        return min(leftFirst, rightFirst) <= k;
    }
};