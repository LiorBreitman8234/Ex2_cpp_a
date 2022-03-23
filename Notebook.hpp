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

#define ROW_LENGTH 100
#define CHAR_UP_LIMIT 126
#define CHAR_LOW_LIMIT 33
namespace ariel {
    class Page {
        int id;
        std::map<std::pair<int, int>, char> tiles;

    public:
        explicit Page(int id)
                : tiles(std::map<std::pair<int, int>, char>()) {
            this->id = id;
        };

        /**
         *
         * @param row the row number(key in our map)
         * @param column column number(index in the vector)
         * @param toWrite the char to write
         */
        void writeToPage(int row, int column, char toWrite);

        /**
         *
         * @param row row number to read from
         * @param column column number to read from
         * @return
         */
        char readFromPage(int row, int column);
    };

    class Notebook {
        std::map<int, Page> pages;
        std::map<int, Page> &pagesRef;

        static int checkInputWrite(int page, int row, int column, const std::string &toWrite, Direction direction);

        static int checkInputReadAndErase(int page, int row, int column, int length, Direction direction);

    public:
        Notebook()
                : pages(std::map<int, Page>()), pagesRef(pages) {};

        void write(int page, int row, int column, Direction direction, std::string toWrite);

        std::string read(int page, int row, int column, Direction direction, int length);

        void erase(int page, int row, int column, Direction direction, int length);

        void show(int num);
    };

}
#endif //EX2_CPP_QA_NOTEBOOK_HPP
