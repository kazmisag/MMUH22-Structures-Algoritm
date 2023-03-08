#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

using namespace std;

#define MSG "Please use following format:\n"      \
            "case sensitive search \t[-c]\n"      \
            "case insensitive search \t[-i]\n"    \
            "file type search \t[--file-type=]\n" \
            "e.g: case sensitive search \t"       \
            "[ $ file_crawler.exe -i --file-type=txt,md ]\n"

// Forward declare files listing function
void search_files(string dir_name, string key_word, string search_flag, string file_extension);

void parse_argv(string input_argv, string &search_flag, string &file_extension)
{

    if (input_argv.compare("-i") == 0)
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
        file_extension = input_argv.substr(12, input_argv.length());
        return;
    }
    else
    {
        cout << "unknown argument: " << input_argv << endl;
    }
}

///////////////////////////////////////////
int main(int argc, char *argv[])
{
    string input_keyword, input_dir, search_flag, file_extension;

    // Code to check if flags [-i], [-c], [--file-type]  has been used

    if (argc >= 2)
    {
        // cout << argv[0] << argv[1] << argv[2] << endl;

        cout << "Please enter a keyword to search: ";
        cin >> input_keyword;
        cout << "Please enter the complete path of the directory you want to search\n";
        cin >> input_dir;
        for (int i = 1; i < argc; i++)
        {
            string input_argv = argv[i];
            parse_argv(input_argv, search_flag, file_extension);
        }
        if ((search_flag.compare("c") == 0) || (search_flag.compare("i") == 0) && (!file_extension.empty()))
        {
            cout << file_extension << endl;
            char temp_ext[file_extension.size() + 1];
            strcpy(temp_ext, file_extension.c_str());
            char *f_ext = std::strtok(temp_ext, ",");
            while (f_ext != NULL)
            {
                cout << "Looking for files with extension: " << f_ext << endl;

                search_files(input_dir, input_keyword, search_flag, f_ext); // call recursive function to search for keyword
                f_ext = std::strtok(NULL, ",");
            }
        }
        else
        {
            search_files(input_dir, input_keyword, search_flag, file_extension); // pass empty variables}
        }
    }
    else
    {
        cout << MSG << endl; // Print error message with hints to execute the file correctly
    }
    return 0;
} ////////////////////////////////////////////////

void search_files(string dir_name, string key_word, string search_flag, string file_extension)
{

    DIR *dir = opendir(dir_name.c_str()); // get dir handle with path e.g working directory

    if (dir == NULL)
    {
        cout << "Error.... File could not be opened or invalid path\n";
        return; // terminate function and return control to main program
    }

    // cout << "Retrieving files from directory $ " << dir_name << endl;
    struct dirent *dirPtr; // Get a pointer to directory
    dirPtr = readdir(dir); // read the directory

    bool is_kw_found = false; // Flag if the keyword is found
    while (dirPtr != NULL)
    {
        if (dirPtr->d_type == DT_REG) // Check if this is a regular file
        {
            // Code to compare file extension
            string f_path = dir_name + "/" + dirPtr->d_name; // concatenate full file path
            size_t ext;
            std::ifstream file_reader;
            if (!file_extension.empty())
            {
                ext = f_path.rfind("." + file_extension, f_path.length());
                if (ext != std::string::npos)
                {
                    file_reader.open(f_path, std::ifstream::in); // open the file with a pointer
                }
            }
            else
            {
                file_reader.open(f_path, std::ifstream::in); // open the file with a pointer
            }

            if (file_reader.is_open())
            {
                string line;
                while (getline(file_reader, line))
                {
                    size_t kw_found;

                    if ((search_flag == "i"))
                    {
                        transform(line.begin(), line.end(), line.begin(), ::tolower); // change file line to lowercase
                        kw_found = line.find(key_word);
                    }
                    if ((search_flag.compare("c") || search_flag.empty()))
                    {
                        kw_found = line.find(key_word);
                    }
                    if (kw_found != std::string::npos)
                    {
                        // cout << line << endl; // print each line
                        cout << "Keyword found in: $ " << f_path << endl;
                        is_kw_found = true; // Keyword found set flag
                    }
                }
                file_reader.close(); // close the file
            }
            else
            {
                std::cout << "Unable to open the file: " << f_path << std::endl;
            }
        }
        // else
        // {
        //     cout << "Sorry! There are no files found with this extension: " << file_extension << endl;
        // }

        // check if this directory and skip "." and ".." in recursive calls
        if ((dirPtr->d_type == DT_DIR) && strcmp(dirPtr->d_name, ".") != 0 && strcmp(dirPtr->d_name, "..") != 0)
        {
            string d_path = dir_name + "/" + dirPtr->d_name; // Concatenate full directory path for next recursive call

            // Make recursive call by passing the new path
            search_files(d_path, key_word, search_flag, file_extension);
        }
        dirPtr = readdir(dir); // read the directory
    }
    closedir(dir); // close directory ptr
    if (!is_kw_found)
    {
        cout << "Sorry! The Keyword: " << key_word << " not found\n";
    }
} // end search_files
