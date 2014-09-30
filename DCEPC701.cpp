#include <fstream>
#include <functional>
#include <climits>
#include <vector>
#include <queue>
#include <iostream>
#include <assert.h>
#include <map>
#include <stdlib.h>
#include <algorithm> 

#define mp make_pair

using namespace std;

#define LL long long

#define adjlist_t map<pair<int,int>,vector<node> >;

inline void scan(int *a) {
    register char c=0;
    while (c < 33)
        c = getchar();
    *a = 0;
    while (c > 33) {
        *a = *a * 10 + c - '0';
        c = getchar();
    }
}
static void print(int n) {
#define BSIZE 16
    char buf[BSIZE];
    int bn = BSIZE-1;
    while (1) {
        buf[bn--] = '0'+(n%10);
        n = n / 10;
        if (n == 0) break;
    }
    while (bn<BSIZE-1) putchar(buf[++bn]);
    putchar('\n');
}

struct node {
  int tower;
  int floorNum;
  int weight;
  node(int t, int f, int w) : tower(t), floorNum(f), weight(w) { };
  node() { }
};

class CompareGreater {
  public:
    bool const operator()(node &nodeX, node &nodeY) {
      return (nodeX.weight > nodeY.weight) ;
    }
};

map<pair<int,int>,vector<node> > adj;

void addEdge(int srcT, int srcF, int destT, int destF, int weight) {
    adj[mp(srcT, srcF)].push_back(node(destT, destF, weight));
    //adj[mp(destT, destF)].push_back(node(srcT, srcF, weight));
}

int dijkstra(node startNode, node finalNode, int V) {

  int counter = 0;

  map<pair<int,int>,int>weight;

  for (map<pair<int,int>,vector<node> >::iterator it = adj.begin(); it != adj.end(); it++) {
            weight[mp(it->first.first, it->first.second)] = INT_MAX;
  }

  priority_queue<node, vector<node>, CompareGreater> Q;
  
  node currentNode;
  weight[mp(startNode.tower, startNode.floorNum)] = 0;
  //cout<<"tower = "<<startNode.tower<<" floor = "<<startNode.floorNum<<endl;
  Q.push(startNode);

  while (!Q.empty()) {
    currentNode = Q.top();
    int currentTower = currentNode.tower;
    int currentFloor = currentNode.floorNum;
    int currentWeight = weight[mp(currentTower, currentFloor)]; 

    if (currentTower == finalNode.tower && currentFloor == finalNode.floorNum) {
      break;
    }
    //cout<<"check 6"<<endl;
    Q.pop();
    //cout<<"check 7"<<endl;
    int x,y;

    if (currentNode.weight <= weight[mp(currentTower, currentFloor)]) {
      for (vector<node>::iterator it = adj[mp(currentTower, currentFloor)].begin(); it != adj[mp(currentTower, currentFloor)].end(); ++it) {
        int adjacentNodeWeight = it->weight - counter;
        //cout<<"adjacentNodeWeight = "<<it->weight<<" new adjacentNodeWeight = "<<adjacentNodeWeight<<endl;
        if (adjacentNodeWeight <= 0) adjacentNodeWeight = 1;
        if (weight[mp(it->tower, it->floorNum)] > currentWeight + adjacentNodeWeight) {
          //cout<<"inside second if currentTower = "<<currentTower<<" currentFloor = "<<currentFloor<<" weight = "<<it->weight<<endl;
          weight[mp(it->tower, it->floorNum)] = currentWeight + adjacentNodeWeight;
          x = adjacentNodeWeight;
          Q.push(node(it->tower, it->floorNum, weight[mp(it->tower, it->floorNum)]));
        }
      }
      counter += x;
      //cout<<"Counter = "<<counter<<endl;
    }
  }
  return weight[mp(finalNode.tower, finalNode.floorNum)];
}

int main() {

  int T;
    scan(&T);
    while (T--) {
        int M, N;
        scan(&M);
        scan(&N);
        int V = M * N;
        adj.clear();
        string maze[M];
        int weight[M][N];
        for (int i = 0; i < M; ++i) {
          cin>>maze[i];
        }
        for (int i = 0; i < M; ++i) {
          for (int j = 0; j < N; ++j) {
            scan(&weight[i][j]);
          }
        }

        for (int i = 0; i < M; ++i) {
          for (int j = 0; j < N; ++j) {
            if (i != 0 && j != N-1) {
              addEdge(i,j,i-1,j, maze[i-1][j] == '.' ? 1 :  weight[i-1][j]);
              addEdge(i-1,j,i,j, maze[i][j] == '.' ? 1 :  weight[i][j]);
              
              addEdge(i,j,i,j+1, maze[i][j+1] == '.' ? 1 :  weight[i][j+1]);
              addEdge(i,j+1,i,j, maze[i][j] == '.' ? 1 :  weight[i][j]);
              continue;
            }
            if (i != 0 && j == N-1) {
              addEdge(i,j,i-1,j, maze[i-1][j] == '.' ? 1 :  weight[i-1][j]);
              addEdge(i-1,j,i,j, maze[i][j] == '.' ? 1 :  weight[i][j]);
              continue;
            }
            if (i == 0 && j != N-1) {
              addEdge(i,j,i,j+1, maze[i][j+1] == '.' ? 1 :  weight[i][j+1]);
              addEdge(i,j+1,i,j, maze[i][j] == '.' ? 1 :  weight[i][j]);
              continue;
            }
          }
        }
        int parentX, parentY, childX, childY;
        scan(&parentX); scan(&parentY); scan(&childX); scan(&childY);
        print(dijkstra(node(parentX, parentY, 0), node(childX, childY, 0), V));
    }

  return 0;
}

