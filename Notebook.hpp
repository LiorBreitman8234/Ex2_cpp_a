//
// Created by bravo8234 on 20/03/2022.
//

#ifndef EX2_CPP_QA_NOTEBOOK_HPP
#define EX2_CPP_QA_NOTEBOOK_HPP
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include "Page.hpp"
#include "Direction.hpp"
namespace ariel
{
    class Notebook
    {
        std::map<unsigned int, Page> pages;
        std::map<unsigned int,Page>& pagesRef;

    public:
        Notebook()
        : pages(std::map<unsigned int,Page>()), pagesRef(pages){};
        void write(unsigned int page,unsigned int row, unsigned int column, Direction direction, std::string toWrite);
        std::string read(unsigned int page, unsigned int row,unsigned int column, Direction direction, int length);
        void erase(unsigned int page,unsigned int row,unsigned int column, Direction direction,int length);
        void show(int num);
    };
}
#endif //EX2_CPP_QA_NOTEBOOK_HPP
