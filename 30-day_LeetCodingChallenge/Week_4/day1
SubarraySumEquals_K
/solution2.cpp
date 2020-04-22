class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m.insert({0,1});
        int n = nums.size();
        int psum[n];
        psum[0] = nums[0];
        for(int i = 1;i<n;i++){
            psum[i] = psum[i-1] + nums[i];
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            auto it  = m.find(psum[i] - k);
            if(it!=m.end()){
                ans += it->second;
            }
            m[psum[i]]++;
        }
        
        return ans;
    }
};