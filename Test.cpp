//
// Created by bravo8234 on 22/03/2022.
//
#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>


TEST_CASE("good writing and reading")
{
    ariel::Notebook notebook;
    notebook.write();
}