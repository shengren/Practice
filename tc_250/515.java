import java.util.*;

public class RotatedClock {
    public String getEarliest(int hourHand, int minuteHand) {
        int s = hourHand % 30;
        int offset = (s * 12 + 360 - minuteHand) % 360;
        if (offset % 30 != 0)
            return "";
        hourHand = (hourHand + offset) % 360;
        minuteHand = (minuteHand + offset) % 360;
        return String.format("%02d:%02d", hourHand / 30, minuteHand / 6);
    }
}