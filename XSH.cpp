#include "XSH.h"

//splits input into separate commands by the pipe symbol
vector<string> split_pipes(string& inputLine) {
    vector<string> commands;
    istringstream ss(inputLine);
    string token;
    
    while(getline(ss, token, '|')) {
        commands.push_back(token);
    }
    
    return commands;
}

//tokenize command string into argv
vector<char*> tokenize_commands(string& command) {
    vector<char*> args;
    istringstream iss(command);
    string word;

    while(iss >> word) {
        args.push_back(strdup(word.c_str()));
    }
    args.push_back(nullptr);

    return args;
}



//trims the white space for 
//more than one command
string trim(string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}


int main() {
    //gets edoras username
    const char* username = getenv("USER");
    string inputLine;


    while(true) {
        cout << username << "% ";
        cout.flush();
        if(!getline(cin, inputLine)) break; //reads entire line
        
        inputLine = trim(inputLine);
        if(inputLine == "exit") break;
        if(inputLine.empty()) continue;

        vector<string> commands = split_pipes(inputLine);
        
        
        int n_commands = commands.size();
        //using 2 pipes
        //[n][0] for read
        //[n][1] for write
        int pipes[2][2];

        for(int i = 0; i < n_commands; ++i) {
            if(i < n_commands-1) {
                //uses pipe for this command's
                //output to the next command
                pipe(pipes[i%2]);
            }

            pid_t pid = fork();

            if(pid==0) {
                //create child process

                if(i>0) {
                    //if not the first command
                    //get input from previous pipe
                    dup2(pipes[(i+1)%2][0], STDIN_FILENO);
                }

                if(i<n_commands-1) {
                    //if not the last command
                    //send output to current pipe
                    dup2(pipes[i%2][1], STDOUT_FILENO);
                }

                //close all pipe fds in child
                close(pipes[0][0]);
                close(pipes[0][1]);
                close(pipes[1][0]);
                close(pipes[1][1]);

                //execute command
                vector<char*> args = tokenize_commands(commands[i]);
                execvp(args[0], args.data());
                perror("execvp");
                exit(1);

            }

            //close parent process pipes
            if(i>0) {
                close(pipes[(i+1)%2][0]);
                close(pipes[(i+1)%2][1]);
            }
        }

        for(int i = 0; i < n_commands; ++i) {
            wait(nullptr);
        }

        
                
        //check if command has 1 or 2 tokens
        //if size 1 run single command
        //if size 2+ run pipeline
    }
           
    return 0;
}
