#include "../include/class.h"

Exercise::Exercise(int exercise_number, std::string path)
{
    path_ = path;
    exercise_number_ = exercise_number;
    std::ifstream file("./"+path_);
    extention_ = this->extract_extention();
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
std::string Exercise::get_extention(){ return extention_; }
std::vector<std::string> Exercise::compile()
{
    std::vector<std::string> output;
    std::string line;
    if(this->extention_ == "cpp"){
        std::string command = "g++ ./" + path_ + " -o ex";
        std::string run = "./ex > temp.txt";
        std::system(command.c_str());
        std::system(run.c_str());
        std::system("rm ex");
    }
    if(this->extention_ == "py")
    {
        std::string commnad = "python3 " + path_ +" > temp.txt";
        std::system(commnad.c_str());
    }
    std::ifstream program_output("./temp.txt");
    while(std::getline(program_output, line))
    {
        output.push_back(line);
    }
    std::system("rm temp.txt");
    std::cout<<this->path_<<" compiled\n";
    return output;
}

std::string Exercise::extract_extention()
{
    std::size_t dot_position = path_.find(".");
    return path_.substr(dot_position + 1, path_.back());
}

void Exercise::append_to_report(std::ofstream* output)
{
    *output << "## ex " << exercise_number_ << "\n```" << this->extention_ << "\n";
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
    std::cout<<"exercise no. "<<this->exercise_number_<<" appended to the report\n";
}