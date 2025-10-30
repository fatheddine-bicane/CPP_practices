#pragma once

#include <fstream>
#include <iostream>
#include <execution>

#define GREEN "\001\033[32m\002"
#define RED   "\001\033[31m\002"
#define YELLOW "\001\033[0;33m\002"
#define RESET "\001\033[0m\002"


namespace fileFormater {

void	replaceFileContent(std::string fileName, std::string s1 ,std::string s2);
void	mainRunner(int argc, char *argv[]);

}
