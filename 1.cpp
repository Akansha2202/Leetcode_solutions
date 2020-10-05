class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> ans;
        if(nums.size()<2)
            return ans;
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i])>0){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};
