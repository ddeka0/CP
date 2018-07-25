#include <bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

using namespace std;
template<typename T>
void LOG(T const& t) {std::cout<<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
#define show(a) std::cout << #a << ": " << (a) << std::endl

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");
const std::string background_delim("&");
const std::string series_delim("&&");
const std::string parallel_delim("&&&");

string user_cmd;
vector<string> executable_cmd;

/*
this function will split the command string entered by the user
*/
void parse_cmd() {
	stringstream ss(user_cmd);
	string x;
	while(ss >> x) {
		executable_cmd.push_back(x);
	}
}
int get_num_command() {
	return (int)(executable_cmd.size());
}
void print_error(string text) {
	cout<<red;
	LOG(text);
	cout<<reset;
}
void print_info(string text) {
	cout<<yellow;
	LOG(text);
	cout<<reset;	
}
/*
sanity check for the user command
*/
bool check_cmd() {
	bool is_background_char_exits = (find(executable_cmd.begin(), executable_cmd.end(),background_delim) != executable_cmd.end());
	bool is_parallel_char_exits = (find(executable_cmd.begin(), executable_cmd.end(),parallel_delim) != executable_cmd.end());
	bool is_series_char_exits = (find(executable_cmd.begin(), executable_cmd.end(),series_delim) != executable_cmd.end());
	// only one of these will be posiible at a time
	if(executable_cmd.size() > 0) {
		if(executable_cmd[0] == "&" 
			or executable_cmd[0] == "&&" 
			or executable_cmd[0] == "&&&"
			or executable_cmd[(int)(executable_cmd.size()) - 1] == "&&" 
			or executable_cmd[(int)(executable_cmd.size()) - 1] == "&&&") {
			print_error("format error");
			return false;
		}
	}
	if( is_background_char_exits && (executable_cmd[ (int)(executable_cmd.size()) - 1] != background_delim) ) {
		print_error("background_delim must be at the end");
		return false;
	}
	if( is_series_char_exits && is_parallel_char_exits ) {
		print_error("eries_cmd and par_cmd can not be intermixed");
		return false;
	}
	if( (is_series_char_exits || is_parallel_char_exits) && executable_cmd.size() <=2 ) {
		print_error("insufficient command for series or parallel execution");
		return false;
	}	
	return true;
}

void handle_cmd_error() {
	LOG("do someting with the command");
}
void start_single_cmd(string cmd) {
	const char* argv[] = { cmd.c_str(), (char*)NULL };
	if (execvp(argv[0], (char* const*)argv) == -1) {
		print_error("problem with " + cmd);
	}
	exit(EXIT_FAILURE);
}
void execute_cmd() {
	bool is_background_char_exits = (find(executable_cmd.begin(), executable_cmd.end(),background_delim) != executable_cmd.end());
	bool is_parallel_char_exits = (find(executable_cmd.begin(), executable_cmd.end(),parallel_delim) != executable_cmd.end());
	bool is_series_char_exits = (find(executable_cmd.begin(), executable_cmd.end(),series_delim) != executable_cmd.end());
	// one string command
	if(executable_cmd.size() == 0) {
		return;
	}
	if(get_num_command() == 1) {
		int status;
		pid_t pid = fork();
		if(pid == 0) {
			signal(SIGINT,SIG_DFL);
			start_single_cmd(executable_cmd[0]);
		}else {
			
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		return;
	}
	if(!is_background_char_exits && is_series_char_exits && !is_parallel_char_exits) {
		for(int i = 0;i<(int)(executable_cmd.size());i+=2) {
			int status;
			pid_t pid = fork();
			if(pid == 0) {
				start_single_cmd(executable_cmd[i]);
			}else {
				do {
					waitpid(pid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
		}
		return;
	}
	if(is_background_char_exits && !is_series_char_exits && !is_parallel_char_exits) {
		cout << "hello" <<endl;
		return;
	}
	print_info("These features are not implemented yet !");
}
int main() {
	signal(SIGINT,SIG_IGN);
	while(true) {
		cout <<green<<"cs744>"<<reset;
		getline(cin,user_cmd);
		parse_cmd();
		if(check_cmd()) {
			execute_cmd();
		}else {
			handle_cmd_error();
		}
		user_cmd.clear();
		executable_cmd.clear();
	}
}