class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Hour hand angle
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        
        // Minute hand angle
        double minuteAngle = minutes * 6;
        
        // Absolute difference
        double angle = abs(hourAngle - minuteAngle);
        
        // Return smaller angle
        return min(angle, 360 - angle);
    }
};