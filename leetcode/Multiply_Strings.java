import java.util.*;
import java.math.BigInteger;

public class Solution {
    public String multiply(String num1, String num2) {
        BigInteger x = new BigInteger(num1);
        BigInteger y = new BigInteger(num2);
        BigInteger res = x.multiply(y);
        return res.toString();
    }
}