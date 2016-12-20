class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.empty() || nums.size() < 4)
            return false;

        //check edge length
        int lengthSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            lengthSum += nums[i];
        }
        if(lengthSum % 4 != 0)
            return false;
        int edge = lengthSum / 4;

        vector<int> edges;
        edges.push_back(0);
        edges.push_back(0);
        edges.push_back(0);
        edges.push_back(0);

        return dfs(nums, edges, edge, 0);
    }

    bool dfs(vector<int>& nums, vector<int>& edges, int edge, int index)
    {
        if(index == nums.size())
            if(edges[0] == edge && edges[1] == edge && edges[2] == edge)
                return true;

        for(int i = 0; i < 4; i++)
        {
            if(i > 0 && edges[i] == edges[i-1])
                continue;
            if(edges[i] + nums[index] <= edge)
            {
                edges[i] += nums[index];
                if(dfs(nums, edges, edge, index+1))
                    return true;
                edges[i] -= nums[index];
            }

        }
        return false;
    }

};
