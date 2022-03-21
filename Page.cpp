//
// Created by bravo8234 on 20/03/2022.
//
#include "Page.hpp"
namespace ariel
{
    void Page::writeToPage(unsigned int row,unsigned int column, char toWrite) {
        if(this->tiles.find({row,column}) == this->tiles.end())
        {
            this->tiles.insert({{row,column},toWrite});
        }
        else
        {
            this->tiles.at({row,column}) =   '~';
        }
    }
    char Page::readFromPage(unsigned int row,unsigned int column) {
        if(this->tiles.find({row,column}) == this->tiles.end())
        {
            return '_';
        }
        return this->tiles.at({row,column});
    }
}
