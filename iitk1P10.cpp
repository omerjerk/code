// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include <iostream>
#include <list>
#include <stdlib.h>
#include <stdio.h>

#define LL long long
#define MAX 11000000
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
 
using namespace std;

int treeMap[110000];
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s) {
    // Mark aint the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    int count = 0;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        //cout<<"dequeing "<<s<<endl;
        if (treeMap[s] == 0) {
            ++count;
        }
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    //cout<<"past the while loop"<<endl;
    print(count);
}
 
int main() {
    // Create a graph given in the above diagram

    int N, Q;
    scan(&N); scan(&Q);
    Graph g(N);
    for (int i = 0; i < N-1; ++i) {
        int x,y;
        scan(&x); scan(&y);
        if (x < y) {
            g.addEdge(x-1, y-1);
        } else {
            g.addEdge(y-1, x-1);
        }
    }

    for (int i = 0; i < N; ++i) {
        scan(&treeMap[i]);
    }

    for (int i = 0; i < Q; ++i) {
        //scanf("%c", &c);
        //cout<<"derp i = "<<i<<endl;
        char c = getchar();
        if (c == '\n') c = getchar();
        //cout<<"character = "<<c<<endl;
        if (c == 'Q') {
            //cout<<"fuck this shit"<<endl;
            int x;
            scan(&x);
            g.BFS(x-1);
            
        } else {
            //cout<<"inside else"<<endl;
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
            treeMap[x-1] += y;
        }
    }
 
    return 0;
}
