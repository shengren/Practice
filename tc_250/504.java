public class MathContest {
	public int countBlack(String ballSequence, int repetitions) {
		String balls = "";
		for (int i = 0; i < repetitions; ++i) balls += ballSequence;
		int res = 0;
		int a = 0;
		int b = balls.length() - 1;
		boolean reversed = false;
		boolean inverted = false;
		while (a <= b) {
			if (!reversed) {
				boolean isBlack = (balls.charAt(a) == 'B');
				++a;
				if (inverted) isBlack = !isBlack;
				if (isBlack) {
					++res;
					inverted = !inverted;
				}
				else {
					reversed = !reversed;
				}
			}
			else {
				boolean isBlack = (balls.charAt(b) == 'B');
				--b;
				if (inverted) isBlack = !isBlack;
				if (isBlack) {
					++res;
					inverted = !inverted;
				}
				else {
					reversed = !reversed;
				}
			}
		}
		return res;
	}
}