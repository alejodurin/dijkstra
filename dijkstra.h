#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include "queue"

class Dijkstra
{
public:
    Dijkstra();
    Dijkstra(Graph& _g);
    void init();
    void relaxation(int current, int adjacent, int weight);
    void dijkstra_algorithm(int initial, int destination, double &average, int &count);
    Graph getGraph();
private:
    const int INF = 1 << 30;
    const static int MAX = 20;
    Graph *graph;
    double average;
    int count;
    int distances[MAX]; // distance[u] distance of vertex initial to vertex with ID = u
    bool visited[MAX]; // To vertex visited.
    int previus[MAX]; // To print paths.
    std::priority_queue< Router, std::vector<Router>, cmp > Q; //We use the defined comparator to the minus valor for this in top.
};

#endif // DIJKSTRA_H
