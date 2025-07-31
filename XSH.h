/*
Team Names: Michael Corn and Simmon Quan

Edoras Usernames: cssc1415 and cssc1450

Assignment #2: Experimental Shell "XHS"

File Name: XSH.h
*/


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

vector<string> arguments;

vector<string> split_pipes(string& input);

vector<char*> tokenize_commands(string& command);

vector<int> create_pipes(int n);

string trim(string& s);

void run_shell();

void run_pipelines(vector<string>& commands);

