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

bool compareByFloor(const node &a, const node &b) {
    return a.floorNum < b.floorNum;
}

//void doStuff();
//void dijkstra(node, int, int, vector< list<node> >*);
//void addEdge(int, int, int, vector< list<node> >*);

map<pair<int,int>,vector<node> > adj;

void addEdge(int srcT, int srcF, int destT, int destF, int weight) {
    //adj[src].push_back(node(dest, weight));
    //adj[dest].push_back(node(src, weight));
    adj[mp(srcT, srcF)].push_back(node(destT, destF, weight));
    adj[mp(destT, destF)].push_back(node(srcT, srcF, weight));
}

int dijkstra(node startNode, node finalNode, int V) {

  map<pair<int,int>,int>weight;

  for (map<pair<int,int>,vector<node> >::iterator it = adj.begin(); it != adj.end(); it++) {
            weight[mp(it->first.first, it->first.second)] = INT_MAX;
  }

  priority_queue<node, vector<node>, CompareGreater> Q;
  
  node currentNode;
//cout<<"check 4"<<endl;
  weight[mp(startNode.tower, startNode.floorNum)] = 0;
  //cout<<"check 5"<<endl;
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

    if (currentNode.weight <= weight[mp(currentTower, currentFloor)]) {
      //cout<<"inside first if"<<endl;
      for (vector<node>::iterator it = adj[mp(currentTower, currentFloor)].begin(); it != adj[mp(currentTower, currentFloor)].end(); ++it) {
        if (weight[mp(it->tower, it->floorNum)] > currentWeight + it->weight) {
          //cout<<"inside second if currentTower = "<<currentTower<<" currentFloor = "<<currentFloor<<" weight = "<<it->weight<<endl;
          weight[mp(it->tower, it->floorNum)] = currentWeight + it->weight;
          Q.push(node(it->tower, it->floorNum, weight[mp(it->tower, it->floorNum)]));
        }
      }
    }
  }
  return weight[mp(finalNode.tower, finalNode.floorNum)];
}





int main() {

  int T;
    scan(&T);
    while (T--) {
        int N, F, M;
        scan(&N);
        scan(&F);
        scan(&M);
        int V = N + 2*M;
        adj.clear();
        for (int i = 0; i < N; ++i) {
                if (i != N-1) {
                    //if (j != F-1) addEdge((i*F) + j, (i*F) + j + 1, 1, adj);
                    //if (j==0) addEdge(i*F, ((i+1)*F), 1, adj);
                    addEdge(i, 0, i + 1, 0, 1);
                }
                if (i == N-1) {
                    //if (j != F-1) addEdge((i*F) + j, (i*F) + j + 1, 1, adj);
                    addEdge(i, 0, 0, 0, 1);
                }
        }
        for (int i = 0; i < M; ++i) {
            int fx, tx, fy, ty, w;
            scan(&tx); scan(&fx); scan(&ty); scan(&fy); scan(&w);
            addEdge(tx-1, fx-1, ty-1, fy-1, w);
            addEdge(tx-1, fx-1, tx-1, 0, fx-1);
            //addEdge(tx-1, 0, tx-1, fx-1, fx-1);
            addEdge(ty-1, fy-1, ty-1, 0, fy-1);
            //addEdge(ty-1, 0, ty-1, fy-1, fx-1);
        }
        for (map<pair<int,int>,vector<node> >::iterator it = adj.begin(); it != adj.end(); it++) {
            if (it->first.second != 0) continue;
            for (vector<node>::iterator derp = it->second.begin(); derp != (it->second.end()-1); derp++) {
              //cout<<"past the loop"<<endl;
              if (it->first.first == derp->tower) {
                  addEdge(it->first.first, derp->floorNum, it->first.first, (derp+1)->floorNum,
                  abs(((derp+1)->floorNum) - (derp->floorNum)));
                  //cout<<"("<<it->first.first+1<<","<<derp->floorNum+1<<") --- ("<<it->first.first+1
                  //    <<","<<(derp+1)->floorNum+1<<")"<<endl;
                  //addEdge(it->first.first, (derp+1)->floorNum, it->first.first, derp->floorNum, 
                  //abs(((derp+1)->floorNum) - ((derp+1)->floorNum)));
            }
      }
  }
        int q;
        scan(&q);
        for (int i = 0; i < q; ++i) {
            int qtx, qfx, qty, qfy;
            scan(&qtx); scan(&qfx); scan(&qty); scan(&qfy);
            //cout<<"check 3"<<endl;
            //dijkstra(node(((qtx-1)*F)+(qfx-1), 0), ((qty-1) *F)+ (qfy-1), V, adj);
            if (qtx == qty) {
              print(abs(qfx-qfy));
              continue;
            }

            int nearestStartFloorUp = -1;
            int nearestStartFloorDn = 0;
            int nearestFinalFloorDn = 0;
            int nearestFinalFloorUp = -1;
            vector<node> temp;
            for (vector<node>::iterator it = adj[mp(qtx-1, 0)].begin(); it != adj[mp(qtx-1, 0)].end(); it++) {
              if (it->tower == qtx -1) {
                temp.push_back(node(it->tower, it->floorNum, 0));
              }
            }
            temp.push_back(node(qtx-1, 0, 0));
            sort(temp.begin(), temp.end(), compareByFloor);
            //for (vector<node>::iterator it = temp.begin(); it != temp.end(); it++) {
              //cout<<"( "<<it->tower+1<<" , "<<it->floorNum+1<<" )"<<endl;}
            for (vector<node>::iterator it = temp.begin(); it != temp.end()-1; it++) {
              if ((it)->floorNum <= qfx-1) {
                nearestStartFloorDn = (it)->floorNum;
                nearestStartFloorUp = (it+1)->floorNum;
                break;
              }
            }
            int startDiffUp = abs(qfx-1-nearestStartFloorUp);
            int startDiffDn = abs(qfx-1-nearestStartFloorDn);
            //cout<<"Nearest Floor Down = "<<nearestStartFloorDn+1<<" Nearest Floor Up = "<<nearestStartFloorUp+1<<endl;
            temp.clear();
            for (vector<node>::iterator it = adj[mp(qty-1, 0)].begin(); it != adj[mp(qty-1, 0)].end(); it++) {
              if (it->tower == qty -1) {
                temp.push_back(node(it->tower, it->floorNum, 0));
              }
            }
            temp.push_back(node(qty-1, 0, 0));
            sort(temp.begin(), temp.end(), compareByFloor);
            for (vector<node>::iterator it = temp.begin(); it != temp.end()-1; it++) {
              //cout<<"( "<<it->tower+1<<" , "<<it->floorNum+1<<" )"<<endl;
              if ((it)->floorNum <= qfy-1) {
                nearestFinalFloorDn = (it)->floorNum;
                nearestFinalFloorUp = (it+1)->floorNum;
                //break;
              }
            }
            int finalDiffUp = abs(qfy-1-nearestFinalFloorUp); 
            int finalDiffDn = abs(qfy-1-nearestFinalFloorDn); 
            //cout<<"Nearest Floor Down = "<<nearestFinalFloorDn+1<<" Nearest Floor Up = "<<nearestFinalFloorUp+1<<endl;
            int ans1 = dijkstra(node(qtx-1, nearestStartFloorDn, 0), node(qty-1, nearestFinalFloorDn, 0), V);
            int ans2 = nearestFinalFloorUp == -1 ? -1 :
                dijkstra(node(qtx-1, nearestStartFloorDn, 0), node(qty-1, nearestFinalFloorUp, 0), V);
            int ans3 = nearestFinalFloorUp == -1 || nearestStartFloorUp == -1 ? -1 :
                dijkstra(node(qtx-1, nearestStartFloorUp, 0), node(qty-1, nearestFinalFloorUp, 0), V);
            int ans4 = nearestStartFloorUp == -1 ? -1 :
                dijkstra(node(qtx-1, nearestStartFloorUp, 0), node(qty-1, nearestFinalFloorDn, 0), V);
            //cout<<"ans1 = "<<ans1<<endl<<"ans2 = "<<ans2<<endl<<"ans3 = "<<ans3<<endl<<"ans4 = "<<ans4<<endl;
            ans1 += startDiffDn + finalDiffDn;
            if (ans2 != -1) {
              ans1 = min(ans1, ans2 + startDiffDn + finalDiffUp);
            }
            if (ans3 != -1) {
              ans1 = min(ans1, ans3 + startDiffUp + finalDiffUp);
            }
            if (ans4 != -1) {
              ans1 = min(ans1, ans4 + startDiffUp + finalDiffDn);
            }
            print(ans1);
            //dijkstra(node(qtx-1, qfx-1, 0), node(qty-1, qfy-1, 0), V);
        }
    }

  return 0;
}

