/*
LSR 11-08-02

Greedy from the biggest one after sorting
*/

import java.util.*;  // for Arrays.sort()

public class SlimeXSlimesCity {
    public int merge(int[] population) {
        long sum = 0;
        Arrays.sort(population);  // how to sort a primitive array
        for (int i = 0; i < population.length; ++i)
            sum += population[i];
        int last = population.length - 1;
        for (; last >= 0; --last) {
            if (sum - population[last] < population[last]) break;
            sum -= population[last];
        }
        return population.length - last;
    }
}