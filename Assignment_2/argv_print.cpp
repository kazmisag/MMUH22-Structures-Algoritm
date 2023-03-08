#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Parse argv[]
void parse_argv(string &input_argv, string &f_ext, string &search_flag)
{
    
    if ((string(input_argv).compare("-i") == 0))
    {
        search_flag = "i";
        return;
    }
    if (string(input_argv).compare("-c") == 0)
    {
        search_flag = "c";
        return;
    }
    if (input_argv.substr(0, 12).compare("--file-type=") == 0)
    {
        f_ext = input_argv.substr(13, input_argv.length());
        return;
    }

}

int main(int argc, char *argv[])
{
    string input_argv, f_ext, search_flag;
    for (int i = 1; i < argc; i++)
    {
        input_argv = argv[i];
        parse_argv(input_argv, f_ext, search_flag);
    }
        cout << search_flag <<" "<<f_ext<< endl;

    // if (string(argv[2]).substr(0, 12) == "--file-type=")
    // {
    //     string temp = string(argv[2]).substr(13, strlen(argv[2]));
    //     cout << temp << endl;

    // string ext1;
    // int i = 0;
    // while (temp.find(","))
    // {
    //     ext1.assign(temp, i, temp.find(","));
    //     cout << ext1;
    //     i = temp.find(",");
    // }

    // // const char *delimiters = "=,";

    // int num_of_ext=0;
    // char *f_ext[10];
    // f_ext[num_of_ext]= std::strtok(temp.c_str(), ",");

    // while(f_ext[num_of_ext]!=NULL)
    // {
    //     //cout<<f_ext[num_of_ext]<<endl;
    //     string ext = string(f_ext[num_of_ext]);
    //     cout<<ext<<endl;

    //     f_ext[++num_of_ext] = std::strtok(NULL, delimiters);
    // }
    //    }

    return 0;
}
