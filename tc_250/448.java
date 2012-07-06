import java.util.*;

public class TheBlackJackDivOne {
    int deck[] = {0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 16, 4};
    int numCards;
    double[] p = new double[10];

    public double expected(String[] cards) {
        numCards = 52 - cards.length;
        int rest = 21 - filter(cards);
        f(0, rest, 1.0);
        double ret = 0.0;
        for (int i = 0; i < 10; ++i)
            ret += i * p[i];
        return ret;
    }

    void f(int numExtras, int rest, double prob) {
        if (rest <= 0) {
            p[numExtras] += prob;
            return;
        }
        for (int i = 2; i <= 11; ++i) {
            if (deck[i] == 0) continue;
            --deck[i];
            --numCards;
            f(numExtras + 1, rest - i, prob * (deck[i] + 1) / (numCards + 1));
            ++deck[i];
            ++numCards;
        }
    }

    int filter(String[] cards) {
        int ret = 0;
        for (int i = 0; i < cards.length; ++i)
        {
            int x = getValue(cards[i].charAt(0));
            ret += x;
            --deck[x];
        }
        return ret;
    }

    int getValue(char c) {
        if (c >= '2' && c <= '9') return c - '0';
        if (c == 'A') return 11;
        return 10;
    }
}