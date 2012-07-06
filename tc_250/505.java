/*
LSR 11-08-02

The total area = (R0 + R1 + ... + Rm-1) * (C0 + C1 + ... + Cn-1)
If all rows' length (Rx) can be represent by one specific Ri, the first part can be changed
 to a function of Ri, because each row is a function of Ri.
If each column (Cx) has at least one answer, the second part can be changed to a function of
 1/Ri, because Cx can be represented by Ax/Rx, which is a function of 1/Rx, and Rx is a 
 function of Ri.
To use Ri to represent Rj, the sufficient condition is both Ri and Rj have answers on the 
same column (intersection, sharing a specific Cx).
Note that Ri and 1/Ri will eliminate each other in the calculation of the total area.
So we do not need to know the exact value of Ri.

The dfs is used to find those intersections. It looks like finding connected components.
If the number of such components is N, we need to N-1 queries to connect them.
This is why the answer is "ret-1".
Another thing is these queries have to be put on columns that already have answers (in order 
to build intersections).
Therefore, if there is no answer in a column, above added queries will not be placed on that 
column. Empty columns will remain empty after the previous step.
This is why the algorithm checks all the columns and adds one query for the columns with no 
answer at last.
*/

public class RectangleArea {
    public int minimumQueries(String[] known) {
        int height = known.length;  // length of array
        int width = known[0].length();  // length of String
        boolean[] mark = new boolean[height];  // Use [] to indicate the size; default value is false
        int ret = 0;
        for (int i = 0; i < height; ++i) {
            if (!mark[i]) {
                ++ret;
                dfs(mark, height, width, i, known);
            }
        }
        for (int j = 0; j < width; ++j) {
            boolean have = false;
            for (int i = 0; i < height; ++i) {
                if (known[i].charAt(j) == 'Y') {  // j-th character in i-th String
                    have = true;
                    break;
                }
            }
            if (!have) {
                ++ret;
            }
        }

        return (ret - 1);
    }

    private void dfs(boolean[] mark, int height, int width, int row, String[] known) {
        if (mark[row]) return;
        mark[row] = true;
        for (int i = 0; i < height; ++i) {
            boolean intersect = false;
            for (int j = 0; j < width; ++j) {
                if (known[i].charAt(j) == 'Y' && known[row].charAt(j) == 'Y') {
                    intersect = true;
                    break;
                }
            }
            if (intersect) {
                dfs(mark, height, width, i, known);
            }
        }
    }
}