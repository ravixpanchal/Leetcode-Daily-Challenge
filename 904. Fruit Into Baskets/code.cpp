class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         if (fruits.empty()) return 0;
        
        int left = 0;
        int maxFruits = 0;
        unordered_map<int, int> fruitCount;
        
        for (int right = 0; right < fruits.size(); right++) {
            // Add current fruit to our basket
            fruitCount[fruits[right]]++;
            
            // If we have more than 2 types of fruits, shrink window from left
            while (fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]);
                }
                left++;
            }
            
            // Update maximum fruits collected
            maxFruits = max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
        
    }
};