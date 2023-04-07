#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdio.h>

class Exercise
{
private:
    std::string path_;
    int exercise_number_;
    std::vector<std::string> lines_;
    std::vector<std::string> output_;
public:
    Exercise(int, std::string);
    std::vector<std::string> get_lines();
    std::vector<std::string> get_output();
    std::string get_path();
    int get_exercise_number();
    void append_to_report(std::ofstream*);
    std::vector<std::string> compile();
};

Exercise::Exercise(int exercise_number, std::string path)
{
    path_ = path;
    exercise_number_ = exercise_number;
    std::ifstream file("./"+path_);
    std::string line;
    if(!file.is_open()){ return; }
    while (std::getline(file, line))
    {
        lines_.push_back(line);
    }
    output_ = this->compile();
}
std::string Exercise::get_path() { return path_; }
int Exercise::get_exercise_number() { return exercise_number_; }
std::vector<std::string> Exercise::get_lines(){ return lines_; }
std::vector<std::string> Exercise::get_output(){ return output_; }
std::vector<std::string> Exercise::compile()
{
    std::vector<std::string> output;
    std::string line;
    std::string command = "g++ ./" + path_ + " -o ex";
    std::string run = "./ex > temp.txt";
    std::system(command.c_str());
    std::system(run.c_str());
    std::ifstream program_output("./temp.txt");
    while(std::getline(program_output, line))
    {
        output.push_back(line);
    }
    std::system("rm ex temp.txt");
    return output;
}

void Exercise::append_to_report(std::ofstream* output)
{
    *output << "## ex " << exercise_number_ << "\n```cpp\n";
    for(std::string line : lines_)
    {
        *output << line << "\n";
    }
    *output<<"```\n";
    *output<<"```\noutput:\n";
    for(std::string line : output_)
    {
        *output << line << "\n";
    }
    *output<<"```\n";
}

std::vector<std::string> handle_arguments(int argc, char** argv)
{
    std::vector<std::string> output_vec;
    for(int argument = 0; argument < argc; argument++, *argv++)
    {
        output_vec.push_back(*argv);
    }
    output_vec.erase(output_vec.begin());
    return output_vec;
}

template <typename T>
void print_vector(std::vector<T> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        std::cout<<v[i]<<"\n";
    }
}

int main(int argc, char** argv)
{
    std::vector<std::string> exercise_list = handle_arguments(argc, argv);
    std::ofstream output("./README.md");
    print_vector(exercise_list);
    Exercise lab1(1, exercise_list[0]);
    Exercise lab2(2, exercise_list[1]);
    Exercise lab3(3, exercise_list[2]);
    lab1.append_to_report(&output);
    lab2.append_to_report(&output);
    lab3.append_to_report(&output);
}