class Solution {
   public int integerBreak(int n) 
   {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int twos = 0, threes = n / 3;

        if (n > 3 && n % 3 == 0) return (int)Math.pow(3, threes);

        else if (n % 3 == 1) 
        {
            threes--;
            twos += 2;
        } else twos++;

        return (int)(Math.pow(2, twos) * Math.pow(3, threes));
    }
}