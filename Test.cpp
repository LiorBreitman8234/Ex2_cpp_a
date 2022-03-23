//
// Created by bravo8234 on 22/03/2022.
//
#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>


TEST_CASE("good writing,reading and erasing, short string")
{
    ariel::Notebook notebook;
    notebook.write(1,1,1,ariel::Direction::Horizontal, "Lior");
    CHECK(notebook.read(1,1,1,ariel::Direction::Horizontal,4) == "Lior");
    CHECK(notebook.read(1,1,2,ariel::Direction::Horizontal,4) == "ior_");
    CHECK(notebook.read(1,1,1,ariel::Direction::Vertical,4) == "L___");
    notebook.erase(1,1,1,ariel::Direction::Horizontal,3);
    CHECK(notebook.read(1,1,1,ariel::Direction::Horizontal,4) == "~~~r");
    CHECK(notebook.read(1,0,1,ariel::Direction::Vertical, 4) == "_~__");
}

TEST_CASE("trying to override text")
{
    ariel::Notebook notebook;
    notebook.write(1,1,1,ariel::Direction::Horizontal, "basketball");
    CHECK_THROWS_MESSAGE(notebook.write(1,1,4,ariel::Direction::Horizontal,"abc"),"trying to write on an occupied space");
    CHECK_THROWS_MESSAGE(notebook.write(1,0,1,ariel::Direction::Vertical,"abc"),"trying to write on an occupied space");
}

TEST_CASE("good writing and reading, long text")
{
    std::string toWrite;
    int size = std::rand() % 30 + 20;
    for(int i =0; i < size;i++)
    {
        int letter = rand() % 26 + 97;
        toWrite.push_back(char(letter));
    }
    ariel::Notebook notebook;
    notebook.write(0,0,0,ariel::Direction::Horizontal,toWrite);
    CHECK(notebook.read(0,0,0,ariel::Direction::Horizontal,size) == toWrite);
    notebook.write(0,1,0,ariel::Direction::Vertical,toWrite);
    CHECK(notebook.read(0,1,0,ariel::Direction::Vertical,size) == toWrite);
    CHECK_THROWS(notebook.write(0,2,0,ariel::Direction::Horizontal,"ab"));
}

TEST_CASE("Trying to access index over 100")
{
    ariel::Notebook notebook;
    //write over 100
    CHECK_THROWS(notebook.write(0,0,100,ariel::Direction::Horizontal,"a"));
    CHECK_THROWS_MESSAGE(notebook.write(0,0,100,ariel::Direction::Horizontal,"a"),"trying to write to columns over 100");
    //writing starts under 100 but goes over it
    CHECK_THROWS(notebook.write(0,0,95,ariel::Direction::Horizontal,"aaaaaaaaaa"));
    CHECK_THROWS_MESSAGE(notebook.write(0,0,95,ariel::Direction::Horizontal,"aaaaaaaaaa"),"trying to write to columns over 100");
    //read over 100
    CHECK_THROWS(notebook.read(0,0,100,ariel::Direction::Horizontal,1));
    CHECK_THROWS_MESSAGE(notebook.read(0,0,100,ariel::Direction::Horizontal,1),"trying to read columns over 100");
    //starting before 100 but getting over it
    CHECK_THROWS(notebook.read(0,0,60,ariel::Direction::Horizontal,50));
    CHECK_THROWS_MESSAGE(notebook.read(0,0,60,ariel::Direction::Horizontal,50),"trying to read columns over 100");
    //erase over 100
    CHECK_THROWS(notebook.erase(0,0,100,ariel::Direction::Horizontal,1));
    CHECK_THROWS_MESSAGE(notebook.read(0,0,100,ariel::Direction::Horizontal,1),"trying to erase columns over 100");
    //erase starts under 100 but goes over
    CHECK_THROWS(notebook.erase(0,0,60,ariel::Direction::Horizontal,50));
    CHECK_THROWS_MESSAGE(notebook.erase(0,0,60,ariel::Direction::Horizontal,50),"trying to erase columns over 100");


}

TEST_CASE("bad input, negative numbers")
{
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.write(-1,0,0,ariel::Direction::Horizontal,"abc"));
    CHECK_THROWS(notebook.read(-1,0,0,ariel::Direction::Horizontal,3));
    CHECK_THROWS(notebook.erase(-1,0,0,ariel::Direction::Horizontal,3));
    CHECK_THROWS(notebook.write(0,-1,0,ariel::Direction::Horizontal,"abc"));
    CHECK_THROWS(notebook.read(0,-1,0,ariel::Direction::Horizontal,3));
    CHECK_THROWS(notebook.erase(0,-1,0,ariel::Direction::Horizontal,3));
    CHECK_THROWS(notebook.write(0,0,-1,ariel::Direction::Horizontal,"abc"));
    CHECK_THROWS(notebook.read(0,0,-1,ariel::Direction::Horizontal,3));
    CHECK_THROWS(notebook.erase(0,0,-1,ariel::Direction::Horizontal,3));
    CHECK_THROWS(notebook.read(0,0,0,ariel::Direction::Horizontal,-1));
    CHECK_THROWS(notebook.erase(0,0,0,ariel::Direction::Horizontal,-1));

}