class Solution {
public:
    string decodeString(string s) {
        string result;
        string::iterator itr = s.begin();
        while(itr != s.end())
        {
            if(isalpha(*itr))
                result.push_back(*itr);
            if(isdigit(*itr))
                result += decode(s, itr);
            itr++;
        }
        return result;
    }
    string decode(string& s, string::iterator& itr)
    {
        string decodedStr;

        int times = 0;
        string str;
        while(*itr != '[')
        {
            times = times * 10 + (int) *itr - '0';
            itr++;
        }

        while(*itr != ']')
        {
            if(isdigit(*itr))
                str += decode(s, itr);
            if(isalpha(*itr))
                str.push_back(*itr);
            itr++;
        }

        for(int i = 0; i < times; i++)
            decodedStr += str;

        return decodedStr;
    }
};
