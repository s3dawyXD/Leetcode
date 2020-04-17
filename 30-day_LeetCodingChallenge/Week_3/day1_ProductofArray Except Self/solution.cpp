class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int i ;
        vector<int> ans(n),pref,suf(n+1);
        pref.push_back(1);
        suf[n]=1;
        for(int x:nums)
        {
            pref.push_back(pref.back()*x);
        }
        for(i = n-1;i>=0;i--)
        {
            suf[i] = suf[i+1]*nums[i];
        }
        for(i =0;i<n;i++)
        {
            ans[i] = pref[i]*suf[i+1]; 
            //cout<< ans[i]<<" "<<pref[i]<<" "<<suf[i]<<" "<<endl;
        }
        return ans;
        
    }
};
