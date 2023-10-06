class Solution {
    public int findTheWinner(int n, int k) {
        List<Integer> s = new ArrayList<>();

        // Initialize list
        for (int i = 1; i <= n; i++) {
            s.add(i);
        }

        int idx = 0;

        while (s.size() > 1) {
            idx = (idx + k - 1) % s.size();
            s.remove(idx);
        }

        return s.get(0);
    }
}