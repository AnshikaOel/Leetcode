class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map <int,int> count;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        int j=0;
        for(auto i: count)
        {
            while(i.second>0)
            {
                nums[j]=i.first;
                i.second--;
                j++;
            }
        }
    }
};