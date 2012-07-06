import java.util.*;

public class CubeStickers {
	public String isPossible(String[] sticker) {
		Arrays.sort(sticker);
		for (int i = 0; i < sticker.length; ++i) {
			System.out.println(sticker[i]);
		}
		int diff = 0;
		int haveTwo = 0;
		for (int i = 0; i < sticker.length;) {
			System.out.println(i);
			++diff;
			int cnt = 1;
			while ((i + cnt < sticker.length) && (sticker[i + cnt].equals(sticker[i]))) {
				++cnt;
			}
			if (cnt >= 2) ++haveTwo;
			i += cnt;
		}
		System.out.printf("%d %d%n", diff, haveTwo);
		if (diff >= 6) return "YES";
		if (diff < 3) return "NO";
		return (diff + haveTwo >= 6) ? "YES" : "NO";
	}
}