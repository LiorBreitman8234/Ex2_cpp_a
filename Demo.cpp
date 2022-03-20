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
using namespace std;

int main() {
	ariel::Notebook notebook;
	notebook.write(/*page=*/0, /*row=*/10, /*column=*/5, Direction::Horizontal, "abcde");
	cout << notebook.read(/*page=*/0, /*row=*/10, /*column=*/7, Direction::Horizontal, /*length=*/4) << endl;
		// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	notebook.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
		// throws error because writing the letter y will intersect with the letter c
    cout<< notebook.read(100,99,52,ariel::Direction::Vertical,3);
	notebook.erase(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, /*length=*/2);
		// writes ~ instead of _ in line 99, b in line 100 and _ again in line 99
    cout<< notebook.read(100,99,52,ariel::Direction::Vertical,3);

	//notebook.show(100); // shows the notebook's page in a reasonable way. For example:
		//    98:  _________
		//    99:  ___~_____
		//    100: __a~cd___
		//    101: ___~_____
		//    102: _________
}

