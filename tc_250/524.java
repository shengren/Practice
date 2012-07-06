import java.util.*;

public class MagicDiamonds {
  public static long minimalTransfer(long n) {
    if (n <= 3) return n;
    int sqrt_n = (int)Math.sqrt((double)n);
    boolean[] isNotPrime = new boolean[sqrt_n + 1];
    int[] prime = new int[sqrt_n + 1];
    int num_prime = 0;
    for (int i = 2; i <= sqrt_n; ++i) {
      if (!isNotPrime[i]) {
        prime[num_prime++] = i;
        for (int j = i + i; j <= sqrt_n; j += i)
          isNotPrime[j] = true;
      }
    }
    //System.out.printf("%d\n", num_prime);
    /*
    for (int i = 0; i < num_prime; ++i)
      System.out.printf("%d -- \n", prime[i]);
    */
    boolean isPrime = true;
    for (int i = 0; i < num_prime; ++i)
      if (n % prime[i] == 0) {
        isPrime = false;
        break;
      }
    return isPrime ? 2 : 1;
  }
}