#pragma once

#include <iostream>
#include <vector>
#include <set>

class Graph {

    private:

        typedef struct s_Vector2
        {
            float x;
            float y;
            friend std::ostream& operator << (std::ostream& os, const s_Vector2 vec) {
                os << "X : " << vec.x << " Y : " << vec.y << "\n";
                return os;
            };
            friend bool operator < (const s_Vector2 vec1, const s_Vector2 vec2) {
                if (vec1.x == vec2.x) {
                    return vec1.y < vec2.y;
                }
                return vec1.x < vec2.x;
            };
        }   Vector2;

        float max_x;
        float max_y;
        std::multiset<Vector2> points;

    public:
        Graph();
        void addNewVector(int x, int y);
        void print();
        
        friend std::ostream& operator << (std::ostream& os, const Graph graph);
};