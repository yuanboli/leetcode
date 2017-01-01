class Solution {
public:
    int strongPasswordChecker(string s) {
        int consecutiveLength = 0;

        int hasLower = 0, hasUpper = 0, hasDigit = 0;
        char former;
        vector<int> consecutive;
        for(int i = 0; i < s.size(); i++)
        {
            //check 2
            if(isdigit(s[i]))
                hasDigit = 1;
            if(islower(s[i]))
                hasLower = 1;
            if(isupper(s[i]))
                hasUpper = 1;

            //check 3
            if(i > 0 && s[i] == former)
                consecutiveLength++;
            else
            {
                if(consecutiveLength >= 2)
                consecutive.push_back(consecutiveLength + 1);
                consecutiveLength = 0;
            }
            former = s[i];
        }
        if(consecutiveLength >= 2)
            consecutive.push_back(consecutiveLength + 1);

        //compute changes
        int change1 = 0, change2 = 0, change3 = 0; // change1 is for flag1 and flag2, change2 is for the third condition
        int longStr = 0;
        if(s.size() < 6)
            change1 += (6-s.size());
        if(s.size() > 20)
        {
            longStr = 1;
            change1 += (s.size()-20);
        }

        change2 = (hasDigit == 0) + (hasLower == 0) + (hasUpper == 0);
        for(int i = 0; i < consecutive.size(); i++)
        {
            change3 += (consecutive[i] / 3);
            consecutive[i] = (consecutive[i] + 1) % 3;//now it becomes the remaining number to make one fewer change in change3
            if(consecutive[i] == 0)
                consecutive[i] = 3;
        }
        if(!consecutive.empty())
        sort(consecutive.begin(), consecutive.end());

        int combinedChange = 0;

        //combine 1 and 3
        if(longStr == 0)//string is longer than 20
            while(change1 > 0 && change3 > 0)
            {
                combinedChange++;
                change1--;
                change3--;
                if(change2 > 0)
                    change2--;
            }
        else
        {
            for(int i = 0; i < consecutive.size(); i++)
                if(change1 >= consecutive[i] && change3 > 0)
                {
                    combinedChange += consecutive[i];
                    change1 -= consecutive[i];
                    change3--;
                }
            while(change1 >= 3 && change3 > 0)
            {
                combinedChange += 3;
                change1 -= 3;
                change3--;
            }
        }
        //combine 1 and 2
        if(longStr == 0)
            while(change2 > 0 && change1 > 0)
            {
                combinedChange++;
                change2--;
                change1--;
            }
        //combine 2 and 3
        while(change2 > 0 && change3 > 0)
        {
            combinedChange++;
            change2--;
            change3--;
        }

        return change1 + change2 + change3 + combinedChange;

    }
};
