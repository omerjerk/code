#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <locale>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <fstream>
#include <string>
using namespace std;


//end of header files

#define ONLINE_JUDGE

#define llu long long unsigned
#define lld long long
#define ld long
//end of definitions
//#ifndef ONLINE_JUDGE
#define getchar_unlocked() getchar()
#define putchar_unlocked(x) putchar(x)
//#endif // ONLINE_JUDGE

#define zero(n) memset(n,0,sizeof(n))

#define MAX_NUM 1000000

int scan_d()    {register int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {register int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld()    {register int ip=getchar_unlocked(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {register int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}

//fast output

//no line break
void print_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

//special char
char sp='/';
void printsp_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

inline void scan(string &ret){
    register int a=getchar_unlocked();
    ret="";
    while(a==' '||a=='\n'||a==EOF)
        a=getchar_unlocked();
    while(a!=' '&&a!='\n'&&a!=EOF){
        ret+=(char)a;
        a=getchar_unlocked();
    }
}

struct node {
  int index;
  int weight;
  node() {}
  node(int i, int w) : index(i), weight(w) {}
};

class CompareGreater {
  public:
    bool const operator()(node &nodeX, node &nodeY) {
      return (nodeX.weight > nodeY.weight) ;
    }
};


//###############################################################//

void addEdge(int src, int dest, int weight, vector<node> *adj) {
    //adj[src].push_back(node(dest, weight));
    //adj[dest].push_back(node(src, weight));
    adj[src].push_back(node(dest, weight));
}

int dijkstra(int startNode, int finalNode, vector<node> *adj, int V, int *path) {

  int weight[V];

  for (int i = 0; i < V; ++i) {
      weight[i] = 1000000;
  }

  priority_queue<node, vector<node> , CompareGreater> Q;
  
  node currentNode;
  weight[startNode] = 0;
  Q.push(node(startNode, 0));

  while (!Q.empty()) {
    currentNode = Q.top();

    if (currentNode.index == finalNode) {
      break;
    }
    Q.pop();

    if (currentNode.weight <= weight[currentNode.index]) {
      for (vector<node>::iterator it = adj[currentNode.index].begin(); it != adj[currentNode.index].end(); ++it) {
        if (weight[it->index] > weight[currentNode.index] + it->weight) {
          weight[it->index] = weight[currentNode.index] + it->weight;
          Q.push(node(it->index, weight[it->index]));
          path[it->index] = currentNode.index;
        }
      }
    }
  }
  return weight[finalNode];
}

void findPath(int *path, vector<int>& actualPath, int val) {  
  actualPath.push_back(val);
  if (val == 0) return;
  val = path[val];
  findPath(path, actualPath, val);
}

int main() {
  int T = scan_d();
  while(T--) {
    vector<node> *adj = new vector<node>[100];
    int *path = new int[100];
    vector<int> actualPath;
    zero(path);
    int ladders = scan_d(), snakes = scan_d();
    vector<int> LD;
    for (int i = 0; i < ladders; ++i) {
      int x = scan_d()-1; int y = scan_d() - 1;
      addEdge(x, y, 0, adj);
      LD.push_back(x);
    }
    for (int i = 0; i < snakes; ++i) {
      int x = scan_d()-1; int y = scan_d() - 1;
      addEdge(x, y, 0, adj);
    }
    for (int i = 0; i < 100; ++i) {
      if (adj[i].size() == 0) {
        for(int j = 1; j <= 6; ++j) {
          if ((i + j) > 99) break; 
          addEdge(i, i+j, 1, adj);
          //if (i < 10) {
          //  cout<<"i = "<<i<<" i + j = "<<i+j<<endl;
          //}
        }
      }
    }    
    int weight = dijkstra(0, 99, adj, 100, path);
    println_d(weight);
    /*
    findPath(path, actualPath, 99);
    sort(actualPath.begin(), actualPath.end());
    sort(LD.begin(), LD.end());

    vector <int> c;
    for (int i = 0; i < actualPath.size(); ++i) {
      cout<<actualPath[i]<<" ";
    }
    cout<<endl;
    set_intersection(actualPath.begin(),actualPath.end(),LD.begin(),LD.end(),back_inserter(c));
    println_d(actualPath.size() - c.size() - 1); */
  }
}