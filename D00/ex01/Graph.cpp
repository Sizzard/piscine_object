#include "Graph.hpp"

Graph::Graph() : max_x(0), max_y(0){

}

void Graph::addNewVector(int x, int y) {
    Vector2 toAdd;
    toAdd.x = x;
    toAdd.y = y;
    
    if (x > 50 || y > 50) {
        std::cerr << "Limit is 50, point x: " << x << ", y: " << y << " was not added\n";
        return;
    }
    if (x > max_x) {
        max_x = x;
    }
    if (y > max_y) {
        max_y = y;
    }

    if (points.find(toAdd) == points.end()) {
        points.insert(toAdd);
    }
    else {
        std::cerr << "Vector already exists in graph\n";
    }
}


void Graph::print() {
    for (float y = max_y + 1; y >= 0; y--) {
        std::cout << ">& " << y;
        for (float x = 0; x <= max_x + 1; x++) {
            Vector2 vect;
            vect.x = x;
            vect.y = y;
            if (points.find(vect) == points.end()) {
                std::cout << " .";
            }
            else {
                std::cout << " X";
            }
        }
        std::cout << "\n";
    }
    std::cout << ">&   ";
    for (float i = 0; i <= max_x + 1; i++) {
        std::cout << i << " ";
    }
    std::cout  << "\n" << std::endl;
}

std::ostream& operator << (std::ostream& os, const Graph graph) {
    os << "Points in graph :\n";
    for (std::multiset<Graph::Vector2>::const_iterator it = graph.points.begin(); it != graph.points.end(); it++) {
        os << *it;
    }
    return os;
}