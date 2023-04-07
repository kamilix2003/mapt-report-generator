#include "../include/class.h"

std::vector<std::string> handle_arguments(int argc, char** argv)
{
    std::vector<std::string> output_vec;
    *argv++;
    if(argc > 1)
    {
        for(int argument = 1; argument < argc; argument++, *argv++)
        {
            output_vec.push_back(*argv);
        }
        return output_vec;
    }
    std::string line;
    std::system("ls > temp.txt");
    std::ifstream temp("temp.txt");
    std::string extention;
    while(std::getline(temp, line))
    {
        extention = line.substr(line.find(".")+1,line.back());
        if(extention == "py" || extention == "cpp") {output_vec.push_back(line);}
    }
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

std::ofstream generate_report(std::vector<std::string> exercise_list, std::string report_name = "report")
{
    std::ofstream report(report_name+".md");
    for(std::string exercise : exercise_list)
    {
        Exercise lab(0, exercise);
        lab.append_to_report(&report);
    }
    return report;
}

int main(int argc, char** argv)
{
    if(!verify_requiered_software()) {std::cout<<"missing software!\n"; return 0; }
    std::vector<std::string> exercise_list = handle_arguments(argc, argv);
    generate_report(exercise_list);
}