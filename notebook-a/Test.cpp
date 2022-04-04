/**
 * Test program for notebook exercise.
 * 
 * Author: yakov elkobi
 * Since : 2022-03
 */
#include "Notebook.hpp"
#include "doctest.h"
#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE("good input"){
    Notebook note;
    note.write(0, 0, 0, Direction::Horizontal, "yakov");
    note.write(0, 1, 0, Direction::Vertical, "akov");
    note.write(0, 2, 0, Direction::Vertical, "kov");
    note.write(0, 3, 0, Direction::Vertical, "ov");
    note.write(0, 4, 0, Direction::Vertical, "v");
    CHECK(note.read(0, 0, 0, Direction::Horizontal, 5)== "yakov");
    CHECK(note.read(0, 0, 0, Direction::Vertical, 5)== "yakov");
    CHECK(note.read(0, 1, 0, Direction::Horizontal, 4)== "akov");
    CHECK(note.read(0, 2, 0, Direction::Horizontal, 3)== "kov");
    CHECK(note.read(0, 3, 0, Direction::Horizontal, 2)== "ov");
    CHECK(note.read(0, 4, 0, Direction::Horizontal, 1)== "v");
    CHECK(note.read(0, 0, 1, Direction::Vertical, 4)== "akov");
    CHECK(note.read(0, 1, 1, Direction::Vertical, 2)== "ov");
    note.erase(0, 0, 0, Direction::Horizontal, 1);
    CHECK(note.read(0, 0, 0, Direction::Horizontal, 5)== "~akov");
    CHECK(note.read(0, 0, 0, Direction::Vertical, 5)== "~akov");
    note.erase(0, 1, 1, Direction::Horizontal, 1);
    CHECK(note.read(0, 1, 0, Direction::Horizontal, 4)== "a~ov");
    CHECK(note.read(0, 5, 0, Direction::Horizontal, 4)== "_");
    CHECK(note.read(0, 0, 0, Direction::Horizontal, 7)== "yakov__");
}
TEST_CASE("negtive numbers"){
    Notebook note;
    CHECK_THROWS(note.write(-1, 0, 0, Direction::Horizontal, "y"));
    CHECK_THROWS(note.write(0, -1, 0, Direction::Horizontal, "y"));
    CHECK_THROWS(note.write(0, 0, -1, Direction::Horizontal, "y"));
    CHECK_THROWS(note.read(-1, 0, 0, Direction::Horizontal, 1));
    CHECK_THROWS(note.read(0, -1, 0, Direction::Horizontal, 1));
    CHECK_THROWS(note.read(0, 0, -1, Direction::Horizontal, 1));
    CHECK_THROWS(note.read(0, 0, 0, Direction::Horizontal, -1));
    CHECK_THROWS(note.erase(-1, 0, 0, Direction::Horizontal, 1));
    CHECK_THROWS(note.erase(0, -1, 0, Direction::Horizontal, 1));
    CHECK_THROWS(note.erase(0, 0, -1, Direction::Horizontal, 1));
    CHECK_THROWS(note.erase(0, 0, 0, Direction::Horizontal, -1));
}
TEST_CASE("bad input"){
    Notebook note;
    note.write(0, 0, 96, Direction::Horizontal, "yakov");
    CHECK_THROWS(note.read(0, 0, 96, Direction::Horizontal, 5)); // 101 not in renge
    note.write(0, 0, 0, Direction::Horizontal, "yakov");
    note.erase(0, 0, 0, Direction::Horizontal, 1);
    CHECK_FALSE(note.read(0, 0, 0, Direction::Horizontal, 5)== "yakov"); // shold be ~akov
    CHECK_THROWS(note.write(0, 0, 0, Direction::Horizontal, "y")); // is del ~
    CHECK_THROWS(note.write(0, 0, 1, Direction::Horizontal, "y")); // is alrary writin a
}