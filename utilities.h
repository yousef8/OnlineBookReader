#ifndef _utilities_H_
#define _utilities_H_

#include <iostream>
#include <string>
#include <vector>

int readInt(int low, int high);
int showReadMenu(const std::vector<std::string> &choices, std::string header = "Menu");

#endif