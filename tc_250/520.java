import java.util.*;

public class SRMCodingPhase {
    int useLuck(int[] skills, int luck, int k) {
        if (luck == 0) return 0;
        int u = Math.min(skills[k] - 1, luck);
        skills[k] -= u;
        luck -= u;
        return luck;
    }
    public int countScore(int[] points, int[] skills, int luck) {
        int[] times = new int[skills.length];
        int ret = 0;
        if (skills[0] + skills[1] + skills[2] - luck <= 75) {
            System.arraycopy(skills, 0, times, 0, skills.length);
            int left = luck;
            left = useLuck(times, left, 2);
            left = useLuck(times, left, 1);
            left = useLuck(times, left, 0);
            int score = points[0] - times[0] * 2
                      + points[1] - times[1] * 4
                      + points[2] - times[2] * 8;
            if (score > ret) ret = score;
        }
        if (skills[0] + skills[1] - luck <= 75) {
            System.arraycopy(skills, 0, times, 0, skills.length);
            int left = luck;
            left = useLuck(times, left, 1);
            left = useLuck(times, left, 0);
            int score = points[0] - times[0] * 2
                      + points[1] - times[1] * 4;
            if (score > ret) ret = score;
        }
        if (skills[0] + skills[2] - luck <= 75) {
            System.arraycopy(skills, 0, times, 0, skills.length);
            int left = luck;
            left = useLuck(times, left, 2);
            left = useLuck(times, left, 0);
            int score = points[0] - times[0] * 2
                      + points[2] - times[2] * 8;
            if (score > ret) ret = score;
        }
        if (skills[1] + skills[2] - luck <= 75) {
            System.arraycopy(skills, 0, times, 0, skills.length);
            int left = luck;
            left = useLuck(times, left, 2);
            left = useLuck(times, left, 1);
            int score = points[1] - times[1] * 4
                      + points[2] - times[2] * 8;
            if (score > ret) ret = score;
        }
        if (skills[0] - luck <= 75) {
            System.arraycopy(skills, 0, times, 0, skills.length);
            int left = luck;
            left = useLuck(times, left, 0);
            int score = points[0] - times[0] * 2;
            if (score > ret) ret = score;
        }
        if (skills[1] - luck <= 75) {
            System.arraycopy(skills, 0, times, 0, skills.length);
            int left = luck;
            left = useLuck(times, left, 1);
            int score = points[1] - times[1] * 4;
            if (score > ret) ret = score;
        }
        if (skills[2] - luck <= 75) {
            System.arraycopy(skills, 0, times, 0, skills.length);
            int left = luck;
            left = useLuck(times, left, 2);
            int score = points[2] - times[2] * 8;
            if (score > ret) ret = score;
        }
        return ret;
    }
}