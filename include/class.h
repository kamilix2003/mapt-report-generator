#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdio.h>

class Exercise
{
private:
    std::string path_;
    std::string extention_;
    int exercise_number_;
    std::vector<std::string> lines_;
    std::vector<std::string> output_;
public:
    Exercise(int, std::string);
    std::vector<std::string> get_lines();
    std::vector<std::string> get_output();
    std::string get_path();
    std::string get_extention();
    int get_exercise_number();
    void append_to_report(std::ofstream*);
    std::vector<std::string> compile();
    std::string extract_extention();
};