#include "../include/class.h"

std::vector<std::string> handle_arguments(int argc, char** argv)
{
    *argv++;
    std::vector<std::string> output_vec;
    for(int argument = 1; argument < argc; argument++, *argv++)
    {
        output_vec.push_back(*argv);
    }
    return output_vec;
}

bool verify_requiered_software() //TODO
{
    return 1;
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
    if(!verify_requiered_software()) { return 0; }
    std::vector<std::string> exercise_list = handle_arguments(argc, argv);
    generate_report(exercise_list);
}