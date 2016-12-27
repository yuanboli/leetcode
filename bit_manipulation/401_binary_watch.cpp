class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        if(num == 0)
        {
            result.push_back("0:00");
            return result;
        }
        vector<int> digits(10, 0);
        search(result, num, 0, 0, digits);
        return result;

    }

    void search(vector<string>& result, int num, int used, int curIndex, vector<int> digits)
    {
        if(used == num)
            return;
        if(curIndex >= 10)
            return;

        //do not use this digits
        curIndex++;
        search(result, num, used, curIndex, digits);



        //use this digits
        curIndex--;
        digits[curIndex] = 1;
        used++;
        curIndex++;
        if(used == num && ((digits[0] == 0 || digits[1] == 0) && (digits[4] == 0 || digits[5] == 0 || digits[6] == 0 || digits[7] == 0)))
            result.push_back(getString(digits));

        search(result, num, used, curIndex, digits);



        return;
    }

    string getString(vector<int>& digits)
    {
        int hour = 0;
        int minutes = 0;

        for(int i = 0; i < 4; i++)
            if(digits[i] == 1)
                hour += (8 >> i);

        for(int i = 4; i < 10; i++)
            if(digits[i] == 1)
                minutes += (32 >> (i-4));

        stringstream ss;
        ss <<  hour ;
        ss << ":" << setfill('0') << setw(2) << minutes;
        string str = ss.str();
        return str;
    }
};
