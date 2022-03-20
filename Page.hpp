//
// Created by bravo8234 on 20/03/2022.
//

#ifndef EX2_CPP_QA_PAGE_HPP
#define EX2_CPP_QA_PAGE_HPP
#include <iostream>
#include <stdexcept>
#include <map>
#include <unordered_map>
#include <vector>
namespace ariel
{
    class Page
    {
        unsigned int id;
        std::vector<std::map<unsigned int, char>> columns;
        std::vector<std::map<unsigned int,char>>& columnsRef;

    public:
        explicit Page(unsigned int id)
        : columns(std::vector<std::map<unsigned int, char>>(100)),columnsRef(columns)
        {
            std::cout<< "constructed page: " << id <<std::endl;
            this->id = id;
        };
        /**
         *
         * @param row the row number(key in our map)
         * @param column column number(index in the vector)
         * @param toWrite the char to write
         */
        void writeToPage(unsigned int row,unsigned int column, char toWrite);
        /**
         *
         * @param row row number to read from
         * @param column column number to read from
         * @return
         */
        char readFromPage(unsigned int row,unsigned int column);
    };
}
#endif //EX2_CPP_QA_PAGE_HPP
