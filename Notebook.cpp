//
// Created by bravo8234 on 20/03/2022.
//

#include "Notebook.hpp"
namespace ariel
{

    void Notebook::write(unsigned int page,unsigned int row,unsigned int column, Direction direction, std::string toWrite)
    {
        if(pagesRef.find(page) != pagesRef.end())
        {
            //getting the page to write to
            Page current = pagesRef.at(page);
            std::string toCheck;
            for(unsigned long i =0; i < toWrite.size();i++)
            {
                toCheck.push_back('_');
            }
            //here I use the read function to check if the space we want to write to is empty
            if(toCheck != read(page,row,column,direction,(int)toWrite.size()))
            {
                throw std::invalid_argument("trying to write on an occupied space");
            }
            else
            {
                if(direction == Direction::Vertical)
                {
                    //iterate on the rows
                    for(unsigned int i = 0; i < toWrite.size();i++)
                    {
                        current.writeToPage(i + row, column, toWrite.at(i));
                    }
                }
                else
                {
                    //iterate on the columns
                    for(unsigned int i =0; i < toWrite.size();i++)
                    {
                        current.writeToPage(row, column + i, toWrite.at(i));
                    }
                }
            }
        }
        else
        {
            //creating a new page and adding it to our map
            Page toAdd = Page(page);
            // no need to check if the place is clear since this is a new page
            if(direction == Direction::Vertical)
            {
                for(unsigned int i =0; i < toWrite.size();i++)
                {
                    toAdd.writeToPage(row+i,column,toWrite.at(i));
                }
            }
            else
            {
                for(unsigned int i = 0; i < toWrite.size();i++)
                {
                    toAdd.writeToPage(row,column+i,toWrite.at(i));
                }
            }
            pagesRef.insert({page, toAdd});


        }
    }
    std::string Notebook::read(unsigned int page,unsigned int row,unsigned int column, Direction direction, int length) {
        std::string toRet;
        if(pagesRef.find(page) == pagesRef.end())
        {
            //the page doesn't exist, return default sign
            toRet.resize((unsigned long)length,'_');
            return toRet;
        }
        Page readFrom = pagesRef.at(page);
        if(direction == Direction::Vertical)
        {
            for(unsigned int i =0; i < length;i++)
            {
                toRet.push_back(readFrom.readFromPage(row+i,column));
            }
        }
        if(direction == Direction::Horizontal)
        {
            for(unsigned int i =0; i<length;i++)
            {
                toRet.push_back(readFrom.readFromPage(row,column+i));
            }
        }
        return toRet;
    }
    void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, int length) {
        if(pagesRef.empty() || pagesRef.find(page) == pagesRef.end())
        {
            Page toAdd = Page(page);
            if(direction == Direction::Vertical)
            {
                for(unsigned int i =0; i < length;i++)
                {
                    toAdd.writeToPage(row +i, column, '~');
                }
            }
            else
            {
                for(unsigned int i =0; i < length;i++)
                {
                    toAdd.writeToPage(row, column +i, '~');
                }
            }
            pagesRef.insert({page,toAdd});
        }
        else
        {
            Page& removeFrom = pagesRef.at(page);
            for(unsigned int i =0; i < length;i++)
            {
                if(direction == Direction::Vertical)
                {
                    removeFrom.writeToPage(row+i,column,'~');
                }
                else
                {
                    removeFrom.writeToPage(row, column +i, '~');
                }
            }
        }
    }
}


