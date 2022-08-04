class Solution {
public:
    int mirrorReflection(int p, int q) {
        int x = p, y = q;
        int px = 0, py = 0;
        while (true) {
            if (x == 0 && y == p) return 2;
            if (x == p && y == p) return 1;
            if (x == p && y == 0) return 0;
            
            if (x == 0) x = p;
            else x = 0;
            
            y += q;
            y %= 2 * p;
        }
        
        return -1;
    }
};