import java.util.*;

public class CompositeSmash {
    boolean isPrime(int n) {
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }
    public String thePossible(int N, int target) {
        if (target > N)
            return "No";
        if (target == N)
            return "Yes";
        if (N % target != 0)
            return "No";
        if (isPrime(target))
            return "Yes";
        int prime = 0;
        int count = 0;
        for (int i = 2; i <= target; ++i)
            if (isPrime(i) && target % i == 0) {
                if (prime != 0)
                    return "No";
                prime = i;
                while (target % prime == 0) {
                    target /= prime;
                    ++count;
                }
            }
        if (count > 2)
            return "No";
        int countN = 0;
        while (N % prime == 0) {
            N /= prime;
            ++countN;
        }
        if (count < countN && N == 1)
            return "Yes";
        return "No";
    }
}