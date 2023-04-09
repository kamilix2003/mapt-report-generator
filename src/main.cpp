#include "../include/class.h"

const std::string HELP = 
"\n"
"\t-h display this message\n"
"\t-d directory with source files default: current directory\n"
"\t-f files to add to the report default: *.cpp *.py files in the diractory\n"
"\t-l lab number default: none\n"
"\t-a autor\n"
"\t-r link to repo with source code\n";

std::vector<std::string> add_all_files(Config* config)
{
    std::vector<std::string> output_vec;
    std::string line;
    std::system(("ls "+config->dir+" > temp.txt").c_str());
    std::ifstream temp("temp.txt");
    std::string extention;
    while(std::getline(temp, line))
    {
        extention = line.substr(line.find(".")+1,line.back());
        if(extention == "py" || extention == "cpp") {output_vec.push_back(line);}
    }
    std::system("rm temp.txt");
    return output_vec;
}

std::vector<std::string> handle_arguments(int argc, char** argv, Config* config)
{
    std::vector<std::string> output_vec;
    std::string current_flag, argument;
    bool all_files = true;
    *argv++;
    for(int i = 1; i < argc; *argv++, i++)
    {
        argument = *argv;
        if(argument[0] == '-')
        {
            current_flag = argument;
            if(current_flag == "-h") // HELP
            {
                std::cout<<HELP;
                std::exit(EXIT_SUCCESS);
            }
            continue;
        }
        if(current_flag == "-f") // SOURCE FILES
        {
            all_files = false;
            output_vec.push_back(argument);
            continue;
        }
        if(current_flag == "-l") // LABORATORY NUMBER
        {
            config->lab_number = std::stoi(argument);
            continue;
        }
        if(current_flag == "-a") // SIGNATURE
        {
            config->author = argument;
            continue;
        }
        if(current_flag == "-r") // REPO
        {
            config->repo = argument;
            continue;
        }
        if(current_flag == "-d")
        {
            config->dir = argument;
            continue;
        }
        std::cout<<"INVALID FLAG!\n";
        std::exit(EXIT_FAILURE);
    }
    if(all_files){ output_vec = add_all_files(config); }
    return output_vec;
}

bool verify_requiered_software()
{
    std::string cpp, py;
    std::system("g++ --version > temp.txt");
    std::ifstream temp("temp.txt");
    std::getline(temp, cpp);
    std::system("python3 --version > temp.txt");
    temp.close();
    temp.open("temp.txt");
    std::getline(temp, py);
    std::system("rm temp.txt");
    if(!py.empty() && !cpp.empty()){ return 1; }
    return 0;
}

template <typename T>
void print_vector(std::vector<T> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        std::cout<<v[i]<<"\n";
    }
}

std::ofstream generate_report(std::vector<std::string> exercise_list
    ,Config* config)
{
    std::ofstream report(config->report_name+"_"+std::to_string(config->lab_number)+".md");
    report << "# "<< config->lab_msg << " " 
        << ((config->lab_number == -1) ? "" : std::to_string(config->lab_number)) << "\n";
    if(config->author.length() > 0){ report << config->author << "\n\n"; }
    if(config->repo.length() > 0){ report << "[SOURCE](" << config->repo << ")\n"; }
    for(std::string exercise : exercise_list)
    {
        Exercise lab(int(exercise[exercise.find(".")-1] - '0'), exercise, config->dir);
        lab.append_to_report(&report, config);
    }
    report << "<center> generated with <a href=\"https://github.com/kamilix2003/report-baker\">Report baker</a> </center>";
    return report;
}

int main(int argc, char** argv)
{
    Config Report_config;
    if(!verify_requiered_software() && Report_config.bypass_software_check) {std::cout<<"missing software!\n"; return 0; }
    std::vector<std::string> exercise_list = handle_arguments(argc, argv, &Report_config);
    generate_report(exercise_list, &Report_config);
    std::cout<<"freshly baked report!\n";
}