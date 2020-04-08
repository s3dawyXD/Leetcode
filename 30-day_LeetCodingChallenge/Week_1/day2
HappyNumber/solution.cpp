class Solution {
public:
    bool isHappy(int n) {
        int t = n;
        for(int i=0;i<100;i++)
		{
			t = split(t);
			if(t==1)return 1;
		}
		return 0;
        
    }
    int split(int t)
    {
	stack<int>dig;
	while(t>=10)
	{
		dig.push(pow(t%10,2));
		t/=10;
	}
	dig.push(pow(t,2));
	int temp = 0;
	while(!dig.empty())
	{
		temp+=dig.top();
		dig.pop();
	}
	return temp;
    }
    
};