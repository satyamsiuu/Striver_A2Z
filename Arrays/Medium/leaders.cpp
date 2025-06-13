#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& nums) {
        vector<int> lead;
        int n = nums.size();
        if(!n)
            return lead;
        int max = nums[n-1];
        lead.push_back(max);
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>=max)
            {
                max = nums[i];
                lead.push_back(max);
            }
        }
        reverse(lead.begin(),lead.end());
        return lead;
    }

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    vector<int> b(leaders(a));

    for(int i: b)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}