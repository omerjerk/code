#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <queue>

using namespace std;

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
 
// A structure to represent a node in adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
 
// Structure to represent a min heap node
struct MinHeapNode {
    int  v;
    int dist;
    MinHeapNode() {}
    MinHeapNode(int v,int dist) :v(v),dist(dist){}
    bool operator < (const MinHeapNode &that) const{
                return dist > that.dist;
        }
};
 
// The main function that calulates distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
void dijkstra(struct Graph* graph, int src, int destinationIndex)
{
    int V = graph->V;// Get the number of vertices in graph
    int dist[V];      // dist values used to pick minimum weight edge in cut
 
    // minHeap represents set E
    priority_queue <MinHeapNode> q;
 
    // Initialize min heap with all vertices. dist value of all vertices 
    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
    }

    dist[src] = 0;    
    q.push(MinHeapNode(src, dist[src]));
 
 
    // In the followin loop, min heap contains all nodes
    // whose shortest distance is not yet finalized.
    while (q.size()) {
        // Extract the vertex with minimum distance value
        struct MinHeapNode minHeapNode = q.top();
        q.pop();
        int u = minHeapNode.v; // Store the extracted vertex number
        int distance = minHeapNode.dist;
        if (distance > dist[u]) continue;
        if (u == destinationIndex) {
            break;
        }
        //cout<<" ===== "<<u<<" ===="<<endl;
 
        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
 
            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (dist[u] != INT_MAX && 
                                          pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                //cout<<"Setting dist of index = "<<v<<" to "<<dist[v]<<endl;
 
                // update distance value in min heap also
                q.push(MinHeapNode(v, dist[v]) );
            }
            pCrawl = pCrawl->next;
        }
    }

    print(dist[destinationIndex]);
}
 
 
// Driver program to test above functions
int main() {
    int T;
    scan(&T);
    while (T--) {
        int V;
        scan(&V);
        struct Graph* graph = createGraph(V);
        string cityName[V];
        for (int i = 0; i < V; ++i) {
            cin>>cityName[i];
            int E;
            scan(&E);
            for (int j = 0; j < E; ++j) {
                int dest, weight;
                scan(&dest);
                scan(&weight);
                addEdge(graph, i, dest-1, weight);
            }
        }
        int testOutput;
        scan(&testOutput);
        for (int i = 0; i < testOutput; ++i) {
            string start, destination;
            cin>>start;
            cin>>destination;
            int startIndex = -1, destIndex = -1;
            for (int j = 0; startIndex == -1 || destIndex == -1; ++j) {
                if (start == cityName[j]) startIndex = j;
                if (destination == cityName[j]) destIndex = j;
            }
            dijkstra(graph, startIndex, destIndex);
        }
    } 
    return 0;
}