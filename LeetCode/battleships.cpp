#include <bits/stdc++.h>

class Point {

public:
  int x;
  int y;
  Point() {}
  Point(string point) {
    x = point[point.size() - 1] - 'A';
    y = stoi(point.substr(0, point.size() - 1)) - 1;
  }
};

class Ship {
public:
  Point topLeft;
  Point bottomRight;

  Ship(Point tL, Point bR) {
    topLeft = tL;
    bottomRight = bR;
  }

  int getArea() {
    int width = abs(topLeft.x - bottomRight.x) + 1;
    int height = abs(topLeft.y - bottomRight.y) + 1;
    return width * height;
  }

  int getDamage(vector<Point> points) {
    int hits = 0;
    for (Point &point : points) {
      bool topBound, bottomBound;
      topBound = point.x >= topLeft.x && point.y >= topLeft.y;
      bottomBound = bottomRight.x >= point.x && bottomRight.y >= point.y;

      if (topBound && bottomBound)
        hits++;
    }
    return hits;
  }
};

vector<string> stringParse(string s, string d) {
  vector<string> ans;
  size_t curr = 0, next;
  do {
    next = s.find(d, curr);
    ans.push_back(s.substr(curr, next - curr));
    curr = next + d.size();
  } while (next != string::npos);
  return ans;
}

vector<Ship> parseShips(string &S) {
  vector<Ship> ships;
  if (S.empty())
    return ships;
  vector<string> parsedCoordinates = stringParse(S, ",");
  for (auto coord : parsedCoordinates) {
    vector<string> shipCoord = stringParse(coord, " ");
    if (!shipCoord[0].empty() && !shipCoord[1].empty()) {
      Point p1(shipCoord[0]);
      Point p2(shipCoord[1]);
      Ship ship(p1, p2);
      ships.push_back(ship);
    }
  }
  return ships;
}

vector<Point> parseHits(string &T) {
  vector<Point> ans;
  if (T.empty())
    return ans;
  vector<string> coords = stringParse(T, " ");
  for (auto coord : coords) {
    if (!coord.empty()) {
      Point hit(coord);
      ans.push_back(hit);
    }
  }
  return ans;
}

string solution(int N, string &S, string &T) {
  vector<Ship> ships = parseShips(S);
  vector<Point> hits = parseHits(T);

  int sunken = 0, damaged = 0;

  for (auto ship : ships) {
    int damage = ship.getDamage(hits);
    if (damage > 0) {
      if (damage == ship.getArea()) {
        sunken++;
      } else {
        damaged++;
      }
    }
  }

  string ans = to_string(sunken) + ',' + to_string(damaged);
  return ans;
}
