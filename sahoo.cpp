#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main(){
	int n;
    cin>>n;
    vector<int> a(n);
    priority_queue<pii, vector<pii>, greater<pii>> p;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        p.push({a[i],i});
    }

    cout<<p.top();
}