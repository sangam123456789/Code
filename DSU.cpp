
#include <bits/stdc++.h>
using namespace std;

struct DSU
{
	vector<int> el;
	DSU(int n)
	{
		el = vector<int>(n, -1);
	}
	int find(int x)
	{
		if (el[x] < 0)
		{
			return x;
		}
		return el[x] = find(el[x]);
	}
	int siz(int x)
	{
		return -el[find(x)];
	}
	bool unite(int a, int b)
	{
		int p1 = find(a);
		int p2 = find(b);
		if (p1 == p2)
		{
			return false;
		}
		if (el[p1] > el[p2])
		{
			swap(p1, p2);
		}
		el[p1] += el[p2];
		el[p2] = p1;
		return true;
	}
};

int32_t main()
{
	int n = 5;
    DSU dsu(n);

    cout << dsu.find(1) << " " << dsu.siz(1) << "\n"; // prints the parent of 1 and size of 1.
    dsu.unite(1 , 2);
    cout << dsu.find(1) << " " << dsu.siz(1) << "\n"; // After uniting with 2.


	return (0);
}