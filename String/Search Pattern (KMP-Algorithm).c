//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<int> KMP(string pat){
        int n=pat.length();
        vector<int>lps(n,0);
        int i=1,len=0;
        while(i<n){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else
                {
                    len=lps[len-1];
                }
            }
        }
        return lps;
    }
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int>ans;
            vector<int>lps=KMP(pat);
            int n=txt.length();
            int m=pat.length();
            int i=0,j=0;
            while(i<n){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                    if(j==m){
                        ans.push_back(i-m+1);
                        j=lps[j-1];
                    }
                }
                else
                {
                    if(j==0) i++;
                    else
                        j=lps[j-1];
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
