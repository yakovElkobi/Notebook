/**
 * program for notebook exercise.
 * 
 * Author: yakov elkobi
 * Since : 2022-03
 */
#pragma once
#include "Direction.hpp"
#include <string>
#include <unordered_map>
using namespace ariel;
namespace ariel{
    class Notebook{
    private:
        unsigned int maxRow, minChar, maxChar;
        std::unordered_map <int,std::unordered_map<int, std::unordered_map<int, char>>> note;
        void isCorrect(int page, int row, int col, int len)const;
    public:
    Notebook():maxRow(100), minChar(32), maxChar(125){}
    ~Notebook()=default;
    void write(int page, int row, int col, Direction dir, std::string const &str);
    std::string read(int page, int row, int col, Direction dir, int len);
    void erase(int page, int row, int col, Direction dir, int len);
    void show(int page);
    };
}
