#pragma once

#include <fstream>
#include <iostream>
#include <execution>
#include "./colors.hpp"

namespace fileFormater {

void	replaceFileContent(std::string fileName, std::string s1 ,std::string s2);
void	mainRunner(int argc, char *argv[]);

}
