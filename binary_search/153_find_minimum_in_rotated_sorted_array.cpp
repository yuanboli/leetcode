class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return find(nums, 0, nums.size()-1);

    }

    int find(vector<int>& nums, int left, int right) // should be more than or equal to 2 elements
    {
        int mid = (left + right) / 2;

        if(nums[mid] < nums[right])
            return find(nums, left, mid);
        if(nums[mid] > nums[left])
            return find(nums, mid, right);
        // it should be the only case left which is mid == left

        return min(nums[mid + 1], nums[mid]);
    }
};
