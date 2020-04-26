class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maximum = 0, val;
        //cout<<n<<endl;
        for(int i=0;i<n;i++){
            val = nums[i];
            //cout<<maximum<<", "<<val<<endl;
            if(maximum < i) return false;
            if((n-1) <= val) return true;
            maximum = max(maximum,val+i);
            }
        //cout<<maximum;
        return true;
        }

};