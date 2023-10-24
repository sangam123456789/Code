#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct fenwick{
  public :
    vector<int> bit;
    int siz;
    fenwick(int n)
    {
      siz = n;
      bit.resize(n + 1 , 0);
    }
    void update(int ind , int x)
    {
        while(ind <= siz)
        {
          bit[ind] += x;
          ind += (ind & (- ind));
        }
    }
    int find(int ind)
    {
      int ans = 0;
      while(ind >= 1)
      {
        ans += bit[ind];
        ind -= (ind & (-ind));
      }
      return ans;
    }
};

 int32_t main() {
    int n = 5;
    int a[n] = {1 , 2 , 3 , 4 , 5};
    fenwick tr(n);
    for(int i = 0; i < n; i++)
    {
        tr.update(i + 1 , a[i]);//initializing tr (1-based indexing).
    }
    cout << tr.find(5) << "\n";//sum upto 4th element of array.
 }
