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
    notebook.write(0,100,0,ariel::Direction::Horizontal,"a");

}

