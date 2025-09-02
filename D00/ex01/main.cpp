#include "Graph.hpp"

int main() {
    Graph graph = Graph();
    graph.addNewVector(51, 0);
    graph.addNewVector(2.5, 2);
    graph.addNewVector(4, 2);
    graph.addNewVector(2, 4);
    graph.print();
    std::cout << graph;
}