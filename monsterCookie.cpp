// Do not remove these imports. You may add others if you wish.
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
  Args:
    weaknesses: a string, one character for each cookie weakness.
    grid: a vector<vector<char>> describing the map layout, one char per room

  Returns:
    An int, how many time units it will take the Cookie Monster to reach you.
*/
#define ll long long

// Define a custom comparison operator for comparing our elements in the priority queue (built using set)
struct compareOP
{
  bool operator()(const vector<ll> a, const vector<ll> b) const
  {
    // Compare distances
    if (a[2] == b[2])
    {
      // Compare x values
      if (a[0] != b[0])
        return a[0] < b[0];
      // Compare y values
      else
        return a[1] < b[1];
    }
    return a[2] < b[2];
  }
};


int timeToEscape(string weaknesses, const vector<vector<char>> &grid)
{
  // Create an unordered_map to store weaknesses for faster lookup
  unordered_set<char> w(weaknesses.begin(), weaknesses.end());
  // for (auto c : weaknesses)
  // {
  //   w.insert(c);
  // }

  // Create a grid to store distances from origin to a given cell
  int m = grid.size(), n = grid[0].size();
  vector<vector<ll>> dist(m, vector<ll>(n, LLONG_MAX));

  // For easy iteration over all possible directions
  vector<int> dirX = {-1, 0, 1, 0};
  vector<int> dirY = {0, 1, 0, -1};

  // Priority queue (using set) to keep track of visited cells
  set<vector<ll>, compareOP> pq;

  // Time taken at source is 0
  dist[0][0] = 0;

  // Enqueue  origin with distance 0
  // Set elements have values as [x,y,distance]
  pq.insert({0, 0, 0});

  // Process cells until our priority queue is not empty
  while (!pq.empty())
  {
    // Extract and dequeue top element
    vector<ll> curr = *pq.begin();
    pq.erase(pq.begin());

    // Check all neighbors
    for (int i = 0; i < 4; i++)
    {
      int x = curr[0] + dirX[i];
      int y = curr[1] + dirY[i];
      // Check if the indices are within bounds
      if (!(x >= 0 && x < m && y >= 0 && y < n))
        continue;

      // Retrieve the cost of the current neighbor
      int cost = 1;
      if (w.find(grid[x][y]) != w.end())
      {
        cost = 5;
      }
      else if (grid[x][y] != '.' && grid[x][y] != 'Y')
        cost = 2;

      // If relaxation provides a smaller distance add it to the priority queue and update dist
      if (dist[x][y] > dist[curr[0]][curr[1]] + cost)
      {
        // Update the priority of the neighbor based on new dist
        if (dist[x][y] != LLONG_MAX)
        {
          pq.erase(pq.find({x, y, dist[x][y]}));
        }
        dist[x][y] = dist[curr[0]][curr[1]] + cost;
        pq.insert({x, y, dist[x][y]});
      }
    }
  }

  // Return the shortest path possible to 'Y'
  return (int)dist[m - 1][n - 1];
};

// DO NOT MODIFY BELOW HERE
int main()
{
  string line;
  bool firstArg = true;
  vector<vector<char>> grid = {
      {'M', '.', '.', '.'},
      {'.', '.', '.', '.'},
      {'.', '.', '.', 'Y'},
  };
  string weaknesses;

  // while (getline(cin, line))
  // {
  //   istringstream iss(line);
  //   if (line == "")
  //     continue;
  //   if (firstArg)
  //   {
  //     firstArg = false;
  //     weaknesses = line;
  //   }
  //   else
  //   {
  //     vector<char> v(line.begin(), line.end());
  //     grid.push_back(v);
  //   }
  // }

  cout << timeToEscape(weaknesses, grid) << endl;
}
