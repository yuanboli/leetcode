class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        return NumberWithNDigit(n);
    }
    int NumberWithNDigit(int n)
    {
        if(n == 0)
            return 1;
        if(n == 1)
            return 10;
        if(n > 10)
            return 0 + NumberWithNDigit(n-1);
        else
        {
            int num = 9;
            for(int i = 1; i < n; i++)
            {
                num *= (10 - i);
            }
            return num + NumberWithNDigit(n-1);
        }
    }
};
