#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
namespace ariel{
    
    void Notebook::isCorrect(int page, int row, int col, int len)const{
        if(page < 0 || row < 0 || col < 0 || len < 0){
            throw out_of_range("negative row or col or length:");
        } 
        if(col >= maxRow){
            throw out_of_range("length of row is 100:");
        }
    }
    void Notebook::write(int page, int row, int col, Direction dir, string const &str){
        int len = str.length();
        isCorrect(page, row, col, len);
        if(col+len >= maxRow && dir == Direction::Horizontal){
            throw out_of_range("length of row is 100:");
        }
        for(int i = 0; i < str.length(); i++){
            if(str.at((unsigned int)i) < minChar || str.at((unsigned int)i) > maxChar){
                throw out_of_range("invalid symbol:");
            }
        }
        if(dir == Direction::Horizontal){
            for(int i = 0; i < str.length(); ++i){
                if(note[page][row].count(col+i)!=0 && note[page][row][col+i] !='_'){
                    throw runtime_error("you can not write in a place that is already writtin:");
                }
                note[page][row][col+i] = str.at((unsigned int)i);
            }
        }
        else{
            for(int i = 0; i < str.length(); ++i){
                if(note[page][row+i].count(col)!=0 && note[page][row+i][col]!= '_'){
                    throw runtime_error("you can not write in a place that is already writtin:");
                }
                note[page][row+i][col] = str.at((unsigned int)i);
            }

        }       
    }
    string Notebook::read(int page, int row, int col, Direction dir, int len){
        isCorrect(page, row, col,len);
        if(col+len > maxRow && dir == Direction::Horizontal){
            throw out_of_range("length of row is 100:");
        }
        string ans;
        if(dir == Direction::Horizontal){
            for (int i = 0; i < len; ++i){
                if(note[page][row].count(col+i)!=0){
                    ans += note.at(page).at(row).at(col+i);
                }
                else{
                    ans += '_';
                }
            }
        }
        else{
            for (int i = 0; i < len; ++i){
                if(note[page][row+i].count(col)!=0){
                    ans += note.at(page).at(row+i).at(col); 
                }
                else{
                    ans += '_';
                }
            }    
        }
        return ans;
    }
    void Notebook::erase(int page, int row, int col, Direction dir, int len){
        isCorrect(page, row, col, len);
        if(col+len > maxRow && dir == Direction::Horizontal){
            throw out_of_range("length of row is 100:");
        }
        if(dir == Direction::Horizontal){
            for (int i = 0; i < len; ++i){
                note[page][row][col+i] = '~';
            }
        }
        else{
            for (int i = 0; i < len; ++i){
                   note[page][row+i][col] = '~';
            }
        }
    }
    void Notebook::show(int page){
        if(page < 0){
            throw out_of_range("negative page");
        }
        cout<<note[page][0][0]<<endl;
    }
}