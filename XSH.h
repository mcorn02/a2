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

void exit();

//function to create process and run command
//
//function for pipe (IPC)
