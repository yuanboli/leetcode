class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.empty())
            return result;
        if(nums.size() == 1)
            return result;
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if((!m.empty()) && m.find(nums[i]) != m.end())
            {
                result.push_back(m.find(nums[i])->second);
                result.push_back(i);
                return result;
            }


            m.insert(make_pair(target - nums[i], i));
        }
        return result;
    }
};
