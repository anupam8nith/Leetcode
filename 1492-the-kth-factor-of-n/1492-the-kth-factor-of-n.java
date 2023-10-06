import java.util.ArrayList;
import java.util.List;

class Solution {
    public int kthFactor(int n, int k) {
        List<Integer> ans = new ArrayList<>();
        ans.add(1);
        int count = 1;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ans.add(i);
                count++;
                if (count == k) {
                    return i;
                }
            }
        }

        if (count == 0 && n > 2) {
            return -1;
        }
        if (k > 2 * count) {
            return -1;
        }

        int sz = ans.size();

        for (int i = sz - 1; i >= 0; i--) {
            if (ans.get(i) * ans.get(i) != n) {
                ans.add(n / ans.get(i));
            }
        }

        if (ans.size() < k) {
            return -1;
        }

        return ans.get(k - 1);
    }
}
