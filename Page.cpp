//
// Created by bravo8234 on 20/03/2022.
//
#include "Page.hpp"
namespace ariel
{
    void Page::writeToPage(unsigned int row,unsigned int column, char toWrite) {
        std::map<unsigned int,char>::iterator it;
        it = this->columnsRef.at(column).find(row);
        if(it == this->columnsRef.at(column).end())
        {
            this->columnsRef.at(column).insert({row,toWrite});
        }
        else
        {
            it->second = '~';
        }
    }
    char Page::readFromPage(unsigned int row,unsigned int column) {
        std::map<unsigned int,char>::iterator it;
        it = this->columnsRef.at(column).find(row);
        if(it == this->columnsRef.at(column).end())
        {
            return '_';
        }
        return it->second;
    }
}
