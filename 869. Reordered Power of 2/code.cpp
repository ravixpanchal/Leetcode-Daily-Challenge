class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Get digit count of input number
        vector<int> n_count = getDigitCount(n);
        
        // Check all powers of two up to 10^9
        long long power = 1;
        while (power <= 1000000000) {
            vector<int> power_count = getDigitCount(power);
            
            // If digit counts match, we can reorder n to form this power of 2
            if (n_count == power_count) {
                return true;
            }
            
            power *= 2;
        }
        
        return false;
    }
    
private:
    // Helper function to get digit count array for a number
    vector<int> getDigitCount(long long num) {
        vector<int> count(10, 0);
        while (num > 0) {
            count[num % 10]++;
            num /= 10;
        }
        return count;
    }
};