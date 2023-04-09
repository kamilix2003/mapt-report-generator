#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdio.h>

struct Config
{
    int lab_number = -1;
    std::string report_name = "report";
    std::string lab_msg = "Laboratory";
    std::string ex_msg = "Exercise"; 
    std::string author = "";
    std::string repo = "";
    std::string dir = "./";
    bool bypass_software_check = false;
};

class Exercise
{
private:
    std::string path_;
    std::string dir_;
    std::string extention_;
    int exercise_number_;
    std::vector<std::string> lines_;
    std::vector<std::string> output_;
public:
    Exercise(int, std::string, std::string);
    std::vector<std::string> get_lines();
    std::vector<std::string> get_output();
    std::string get_path();
    std::string get_extention();
    int get_exercise_number();
    void append_to_report(std::ofstream*, Config*);
    std::vector<std::string> compile();
    std::string extract_extention();
};