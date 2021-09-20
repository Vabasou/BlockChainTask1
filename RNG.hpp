
#pragma once

#include <random>

class RandInt{
    private:
        std::random_device rd;
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;

    public:
        RandInt(int low, int high) : mt{rd()}, dist{low,high} {}
        int operator ()() {return dist(mt);}
};