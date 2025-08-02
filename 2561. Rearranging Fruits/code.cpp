class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> count;
        int minVal = INT_MAX;
        
        // Count total frequencies and find minimum value
        for(int num : basket1) {
            count[num]++;
            minVal = min(minVal, num);
        }
        
        for(int num : basket2) {
            count[num]++;
            minVal = min(minVal, num);
        }
        
        // Check if equal distribution is possible
        for(auto& p : count) {
            if(p.second % 2 != 0) return -1;
        }
        
        // Calculate the net difference for each fruit type
        map<int,int> diff;
        for(int num : basket1) {
            diff[num]++;
        }
        for(int num : basket2) {
            diff[num]--;
        }
        
        // Collect all fruits that need to be swapped
        vector<int> toSwap;
        for(auto& p : diff) {
            int fruit = p.first;
            int difference = p.second;
            
            // If difference > 0, basket1 has excess
            // We need to move |difference|/2 of these fruits
            int toMove = abs(difference) / 2;
            for(int i = 0; i < toMove; i++) {
                toSwap.push_back(fruit);
            }
        }
        
        // Sort to pair optimally
        sort(toSwap.begin(), toSwap.end());
        
        long long result = 0;
        int n = toSwap.size();
        
        // Pair smallest with largest
        for(int i = 0; i < n / 2; i++) {
            int fruit1 = toSwap[i];
            int fruit2 = toSwap[n - 1 - i];
            
            // Direct swap cost: minimum of the two fruits
            int directCost = min(fruit1, fruit2);
            
            // Indirect swap cost: 2 * minimum element
            int indirectCost = 2 * minVal;
            
            result += min(directCost, indirectCost);
        }
        
        return result;
    }
};