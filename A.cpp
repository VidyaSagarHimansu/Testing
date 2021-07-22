#include<bits/stdc++.h>
using namespace std;
#define int long long
#define S second 
#define F first
using namespace std;

void sol(){
	int h,w,c;
    cin>>h>>w>>c;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin>>a[i][j];
    
    auto sipos = [&](int i, int j){
        if(i<h && i>=0 && j>=0 && j<w) return a[i][j];
        return (int) 0;
    };
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            a[i][j] = max({a[i][j]+i+j, sipos(i-1,j), sipos(i,j-1)});

    // return;
    vector<vector<int>> b(h, vector<int>(w));
    auto pos = [&](int i, int j){
        if(i<h && i>=0 && j>=0 && j<w) return b[i][j];
        return (int) INT_MAX;
    };
    
    for (int i = h-1; i >= 0; i--)
        for (int j = w-1; j >= 0; j--)
            b[i][j] = min({a[i][j]-i-j, pos(i+1,j), pos(i,j+1)});
    
    int ans = 0;
    auto apos = [&](int i, int j){
        if(i<h && i>=0 && j>=0 && j<w) return b[i][j];
        return (int) 0;
    };
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            ans = max(ans, (int) a[i][j]+max(apos(i+1,j),apos(i,j+1)));

    cout<<ans;
}
signed main(){
	int t=1;
	// cin>>t;
	while(t--){
		sol();
		cout<<'\n';
	}
}