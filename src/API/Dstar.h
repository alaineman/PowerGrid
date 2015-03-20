/* Dstar.h
 *
 * D* Lite pathfinding algorithm.
 *
 * Licensed under the LGPL license.
 * Taken from http://dstarlite.googlecode.com/
 *
 * Written by: James Neufeld (neufeld@cs.ualberta.ca)
 */

#ifndef DSTAR_H
#define DSTAR_H

#include <math.h>
//#include <stack>
#include <queue>
#include <list>
#include <unordered_map>

#define eps (10e-10)

using namespace std;

class state {

 public:
  int x;
  int y;
  pair<double,double> k;
  int num;

  bool operator == (const state &s2) const {
    return ((x == s2.x) && (y == s2.y));
  }
  
  bool operator != (const state &s2) const {
    return ((x != s2.x) || (y != s2.y));
  }
  
  bool operator > (const state &s2) const {
    if (k.first-eps > s2.k.first) return true;
    else if (k.first < s2.k.first-eps) return false;
    return k.second > s2.k.second;
  }

  bool operator <= (const state &s2) const {
    if (k.first < s2.k.first) return true;
    else if (k.first > s2.k.first) return false;
    return k.second < s2.k.second + eps;
  }
  

  bool operator < (const state &s2) const {
    if (k.first + eps < s2.k.first) return true;
    else if (k.first - eps > s2.k.first) return false;
    return k.second < s2.k.second;
  }
   
};

struct ipoint2 {
  int x,y;
};

struct ivec2 {
  int v[2];
};



struct cellInfo {

  double g;
  double rhs;
  double cost;
  

};

class state_hash {
 public:
  size_t operator()(const state &s) const {
    return s.x + 34245*s.y;
  }
};


typedef std::unordered_map<state, cellInfo, state_hash, equal_to<state> > ds_ch;
typedef std::unordered_map<state, ivec2, state_hash, equal_to<state> > ds_oh;
typedef priority_queue<state, vector<state>, greater<state> > ds_pq;

typedef struct{
  list<state> path;
  double cost;

  void clear(){
    path.clear();
    cost = 0.0;
  }

} ds_path;

class Dstar {
  
 public:

  Dstar();
  void   init(int sX, int sY, int gX, int gY);
  void   updateCell(int x, int y, double val);
  void   updateStart(int x, int y);
  void   updateGoal(int x, int y);
  bool   replan();
  void   draw() const;
  void   drawCell(const state &s,float z) const;
  void   queryCell(int x, int y) const;

  ds_path &getPath();
  
 private:
  
  ds_path path;

  double C1;
  double k_m;
  state s_start, s_goal, s_last;
  int maxSteps;  

  state qstate;

  ds_pq openList;
  ds_ch cellHash;
  ds_oh openHash;

  bool   near(double x, double y) const;
  void   makeNewCell(const state &u);
  double getG(const state &u) const;
  double getRHS(const state &u) const;
  void   setG(const state &u, double g);
  void   setRHS(const state &u, double rhs);
  double eightCondist(const state &a, const state &b) const;
  int    computeShortestPath();
  void   updateVertex(state &u);
  void   insert(state u);
  void   remove(const state &u);
  double trueDist(const state &a, const state &b) const;
  double heuristic(const state &a, const state &b) const;
  state  &calculateKey(state &u) const;
  void   getSucc(state u, list<state> &s) const;
  void   getPred(state u, list<state> &s) const;
  double cost(const state &a, const state &b) const; 
  bool   occupied(const state &u) const;
  bool   queuePop();
  bool   isConsistent(const state &u);
};

#endif
