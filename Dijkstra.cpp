#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int , int>>> graph;
vector<int> dist;
void dijkstra(int ind, int m)
{
	set<pair<int, int>> s;
	s.insert({0, ind});
	dist[ind] = 0;
	vector<int> vis1(m, 0);
	while (s.size() > 0)
	{
		pair<int, int> cur = *s.begin();
		int i = cur.second;
		int wt = cur.first;
		s.erase(cur);
		if (vis1[i])
			continue;
		vis1[i] = 1;
		for (auto it : graph[i])
		{
			if (dist[i] + it.second < dist[it.first])
			{
				dist[it.first] = dist[i] + it.second;
				s.insert({dist[it.first], it.first});
			}
		}
	}
	return;
}

int32_t main()
{
	int n = 5;
    graph.resize(n);
    graph[0].push_back({1 , 3});
    graph[1].push_back({0 , 3});

    graph[1].push_back({2 , 5});
    graph[2].push_back({1 , 5});

    graph[1].push_back({3 , 6});
    graph[3].push_back({1 , 6});

    graph[0].push_back({4 , 4});
    graph[4].push_back({0 , 4});

	graph[4].push_back({3 , 1});
	graph[3].push_back({4 , 1});

	dist.resize(n , 1e9);
	dijkstra(0 , n); // shortest paths from node 0.
    
	cout << dist[3] << "\n"; //shortest path to node 3 from 0.
	return (0);
}