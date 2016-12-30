#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> nums;
        dfs(nums, k, n, 0, res);
        return res;
    }

    void dfs(vector<int> nums, int k, int n, int curIndex, vector<vector<int> >& res)// we assume that before the curIndex, the sum does not exceed the target n
    {
        if(curIndex >= k)
            return;

        int sum = 0;
        for(int i = 0; i < curIndex; i++)
            sum += nums[i];

        int last; // which is the last element int the nums, to check whether the nums is ascending
        if(!nums.empty())
        {
            vector<int>::reverse_iterator itr = nums.rbegin(); // if nums is not empty
            last = *itr;
        }
        else
            last = 0;
        if(curIndex + 1 == k) // this should be the last number
        {
            if(n-sum > last && n-sum < 10)
            {
                nums.push_back(n-sum);
                res.push_back(nums);
            }
        }
        else
        {
            for(int i = last + 1; i < 10; i++) // this is not the last number
            {

                if(sum+i < n)
                {
                    if(nums.size() == curIndex)
										    nums.push_back(i);
										else
										    nums[curIndex] = i;
                    dfs(nums, k, n, curIndex+1, res);
                }
            }
        }
        return;
    }

};

void printVector(const vector<vector<int> >& res)
{
    cout << "[";
    for(int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ",";
        }
        cout << "\b";

        cout << "]" << ", ";
    }
		cout << "\b\b";
    cout << "]\n";
}

int main()
{
    Solution s;
    vector<vector<int> > res = s.combinationSum3(3,7);
    printVector(res);
}
