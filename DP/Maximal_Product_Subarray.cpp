class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> maxPdt(n+1,0);
        vector<int> minPdt(n+1,0);
        
        maxPdt[0]=minPdt[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            maxPdt[i]=minPdt[i]=nums[i];
            maxPdt[i]=max(maxPdt[i],max(maxPdt[i-1]*nums[i],minPdt[i-1]*nums[i]));
            minPdt[i]=min(minPdt[i],min(minPdt[i-1]*nums[i],maxPdt[i-1]*nums[i]));
            
            ans=max(ans,maxPdt[i]);
            
        }
        return ans;
    }
};