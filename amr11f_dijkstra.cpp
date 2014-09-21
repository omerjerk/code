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
            //cout<<"----------------------------------------"<<endl;
            //cout<<"i = "<<it->first.first<<" j = "<<it->first.second<<endl;
            //for (vector<node>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt) {
            //  cout<<"tower = "<<jt->tower<<" floor = "<<jt->floorNum<<endl;
            //}
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
        vector<int> ref[N];
        for (int i = 0; i < N-1; ++i) {
                if (i != N-1) {
                    //if (j != F-1) addEdge((i*F) + j, (i*F) + j + 1, 1, adj);
                    //if (j==0) addEdge(i*F, ((i+1)*F), 1, adj);
                    addEdge(i, 0, i + 1, 0, 1);
                    ref[i].push_back(0);
                }
        }
        addEdge(N-1, 0, 0, 0, 1);
        ref[N-1].push_back(0);
        for (int i = 0; i < M; ++i) {
            int fx, tx, fy, ty, w;
            scan(&tx); scan(&fx); scan(&ty); scan(&fy); scan(&w);
            addEdge(tx-1, fx-1, ty-1, fy-1, w);
            ref[tx-1].push_back(fx-1);
            ref[ty-1].push_back(fy-1);
            //addEdge(tx-1, fx-1, tx-1, 0, fx-1);
            //addEdge(ty-1, fy-1, ty-1, 0, fy-1);
        }
        for (int i = 0; i < N; ++i) {
          sort(ref[i].begin(), ref[i].end());
        }
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < ref[i].size()-1; ++j) {
            addEdge(i, ref[i][j], i, ref[i][j+1], ref[i][j+1] - ref[i][j]);
            //cout<<"( "<<i<<" , "<<ref[i][j]<<" ) --- ( "<<i<<" , "<<ref[i][j+1]<<" )"<<endl;
          }
        }

        int q;
        scan(&q);
        for (int i = 0; i < q; ++i) {
            int qtx, qfx, qty, qfy;
            scan(&qtx); scan(&qfx); scan(&qty); scan(&qfy);
            --qtx; --qfx; --qty; -- qfy;
            //cout<<"check 3"<<endl;
            //dijkstra(node(((qtx-1)*F)+(qfx-1), 0), ((qty-1) *F)+ (qfy-1), V, adj);
            if (qtx == qty) {
              print(abs(qfx-qfy));
              continue;
            }

            int nearestStartFloorUp = lower_bound(ref[qtx].begin(), ref[qtx].end(), qfx) - ref[qtx].begin();
            int nearestStartFloorDn = nearestStartFloorUp - 1;
            nearestStartFloorUp = ref[qtx][nearestStartFloorUp];
            if (nearestStartFloorDn >= 0)
              nearestStartFloorDn = ref[qtx][nearestStartFloorDn];

            int nearestFinalFloorUp = lower_bound(ref[qty].begin(), ref[qty].end(), qfy) - ref[qty].begin();
            int nearestFinalFloorDn = nearestFinalFloorUp-1;
            nearestFinalFloorUp = ref[qty][nearestFinalFloorUp];
            if (nearestFinalFloorDn >= 0)
              nearestFinalFloorDn = ref[qty][nearestFinalFloorDn];

            int startDiffUp = abs(qfx-nearestStartFloorUp);
            int startDiffDn = abs(qfx-nearestStartFloorDn);
            //cout<<"Nearest Floor Down = "<<nearestStartFloorDn<<" Nearest Floor Up = "<<nearestStartFloorUp<<endl;

            int finalDiffUp = abs(qfy-nearestFinalFloorUp); 
            int finalDiffDn = abs(qfy-nearestFinalFloorDn); 
            //cout<<"Nearest Floor Down = "<<nearestFinalFloorDn<<" Nearest Floor Up = "<<nearestFinalFloorUp<<endl;

            int ans1 = dijkstra(node(qtx, nearestStartFloorUp, 0), node(qty, nearestFinalFloorUp, 0), V);
            int ans2 = nearestFinalFloorDn == -1 || nearestStartFloorDn == -1 ? -1 :
                dijkstra(node(qtx, nearestStartFloorDn, 0), node(qty, nearestFinalFloorDn, 0), V);
            int ans3 = nearestStartFloorDn == -1 ? -1 :
                dijkstra(node(qtx, nearestStartFloorDn, 0), node(qty, nearestFinalFloorUp, 0), V);
            int ans4 = nearestFinalFloorDn == -1 ? -1 :
                dijkstra(node(qtx, nearestStartFloorUp, 0), node(qty, nearestFinalFloorDn, 0), V);
            cout<<"ans1 = "<<ans1<<endl<<"ans2 = "<<ans2<<endl<<"ans3 = "<<ans3<<endl<<"ans4 = "<<ans4<<endl;
            ans1 += startDiffUp + finalDiffUp;
            if (ans2 != -1) {
              ans1 = min(ans1, ans2 + startDiffDn + finalDiffDn);
            }
            if (ans3 != -1) {
              ans1 = min(ans1, ans3 + startDiffDn + finalDiffUp);
            }
            if (ans4 != -1) {
              ans1 = min(ans1, ans4 + startDiffUp + finalDiffDn);
            }
            print(ans1);
            //cout<<ans1;
            //dijkstra(node(qtx-1, qfx-1, 0), node(qty-1, qfy-1, 0), V);
        }
    }

  return 0;
}

