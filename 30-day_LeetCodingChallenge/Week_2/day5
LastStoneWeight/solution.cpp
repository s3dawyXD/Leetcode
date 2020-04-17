class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ans = 0;
        int temp;
        while(1 < stones.size())
        {
            sort(stones.begin(),stones.end());
            temp = abs(stones[stones.size()-1] -stones[stones.size()-2]);
            stones.erase(stones.end()-1);
            stones.erase(stones.end()-1);
            stones.push_back(temp);
        }
        if(stones.size()==1)
        {
            ans = stones[0];
        }
        return ans;
    }
};