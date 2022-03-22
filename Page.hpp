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
        std::map<std::pair<unsigned int,unsigned int>,char> tiles;

    public:
        explicit Page(unsigned int id)
        : tiles(std::map<std::pair<unsigned int,unsigned int>,char>())
        {
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
