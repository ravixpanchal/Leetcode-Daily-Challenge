class Solution {
public:
    map<string,double> m;

    double solve(int x, int y){
        if(x <= 0 && y <= 0){
            return 0.5;
        }

        if(x <= 0){
            return 1.0;
        }

        if(y <= 0){
            return 0.0;
        }

        string key = to_string(x) + "*" + to_string(y);
        if(m.find(key) != m.end()){
            return m[key];
        }

        double ans = solve(x-100, y) + solve(x-75, y-25) + solve(x-50, y-50) + solve(x-25, y-75);
        m[key] = ans * 0.25;
        return ans * 0.25;
    }
    
    double soupServings(int n) {
        if(n > 4500) return 1.0;
        return solve(n, n);
    }
};