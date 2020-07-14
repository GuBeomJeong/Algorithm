class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour * 30 + (double)minutes / 2;
        double m = 6 * minutes;
        
        double result = abs(h-m);
        
        return result > 180 ? 360 - result : result;
    }
};