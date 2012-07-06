public class LuckyRemainder {
    public int getLuckyRemainder(String X) {
    	long sum = 0L;
    	for (int i = 0; i < X.length(); ++i) sum += X.charAt(i) - '0';
    	sum *= (1L << (X.length() - 1));
    	return (int)(sum % 9);
    }
}