/**
 * program for notebook exercise.
 * 
 * Author: yakov elkobi
 * Since : 2022-03
 */
#pragma once
#include "Direction.hpp"
#include <string>
using namespace ariel;
namespace ariel{
    class Notebook{
    private:
        /* data */
    public:
    void write(int page, int row, int col, Direction dir, std::string const &str);
    std::string static read(int page, int row, int col, Direction dir, int len);
    void erase(int page, int row, int col, Direction dir, int len);
    void show(int page);
    };
    
}
