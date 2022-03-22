/**
 * Demo program for notebook exercise.
 * 
 * Author: Erel Segal-Halevi
 * Edited by: Tal Zichlinsky
 * Since : 2022-01
 */

#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include<iostream>
#include <stdexcept>
#include <random>
using namespace std;

int main() {
	ariel::Notebook notebook;
    std::string toWrite;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniformIntDistribution(20,50);
    int size = uniformIntDistribution(e1);

    std::uniform_int_distribution<int> uniformIntDistribution1(97,122);
    for(int i =0; i < size;i++)
    {
        int letter = uniformIntDistribution1(e1);
        toWrite.push_back(char(letter));
    }
    notebook.write(0,1,0,ariel::Direction::Vertical,toWrite);
    std::cout << notebook.read(0,1,0,ariel::Direction::Vertical,size) << std::endl;
    notebook.write(0,0,0,ariel::Direction::Horizontal,toWrite);
    std::cout << notebook.read(0,0,0,ariel::Direction::Horizontal,size) <<std::endl;

}

