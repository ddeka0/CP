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
set<int> active_pids;
map<int,string> pid_to_name;
string command_to_string(vector<string> cmd) {string ret = "";for(string e:cmd) ret += e;return ret;}
int get_num_command() {return (int)(executable_cmd.size());}
void print_error(string text) {cout<<red; LOG(text); cout<<reset;}
void print_info(string text) {cout<<yellow; LOG(text); cout<<reset;}

void parse_cmd() {
	stringstream ss(user_cmd);
	string x;
	while(ss >> x) {
		executable_cmd.push_back(x);
	}
}
void sig_handler(int signum) {
	return;
}
void sigchld_handler(int signum) {
    pid_t pid;
    int   status;
    while ((pid = waitpid(-1, &status, WNOHANG)) != -1) {
		print_info(pid_to_name[pid] + " collected by my parent !");
        //unregister_child(pid, status);   // Or whatever you need to do with the PID
    }
}
void check_for_active_pids() {
	cout <<"inside check_for_active_pids function "<<endl;
	int status;
	cout << "size of active_pids "<<active_pids.size()<<endl;
	set<int> finished_proc;
	for(int pd:active_pids) {
		int pid = waitpid(pd,&status,WUNTRACED | WNOHANG); // it will not wait
		if(pid > 0 && (WIFEXITED(status) || WIFSIGNALED(status)) ) {
			cout <<" one process exited "<<endl;
			finished_proc.insert(pid);
			//active_pids.erase(active_pids.find(pid));
			print_info("process with pid [" + to_string(pid) + "] : [" + pid_to_name[pid] + "] exited successfully\n");
		}
	}
	for(int e:finished_proc) {
		active_pids.erase(active_pids.find(e));
	}
}
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
bool is_operator(string str) {
	return ((str == "&") || (str == "&&") || (str == "&&&"));
}
void handle_cmd_error() {
	LOG("do someting with the command");
}
void start_single_cmd(vector<string> cmd) { // a command as a vector of strings
											// for example ls -all
											// here we have two strings "ls" and "-all"
											// cmd[0] = "ls" and cmd[1] = "-all"

	// find out the size of this single command
	int n = (int)(cmd.size());
	// allocate (n+1) size const char* array 
	const char* argv[n+1];
	for(int i = 0;i<n;i++) {	// store parts of the command in the array
		argv[i] = cmd[i].c_str();
		cout << argv[i] <<" ";
	}
	argv[n] = (char*)NULL; // store the NULL as well
	cout << endl;

	if (execvp(argv[0], (char* const*)argv) == -1) { // now SIG_DFL will be activated for the child
													 // it will respond to the the ctrl+c from the user
													 // and that is required for the forground processes
		print_error("problem with ");
		for(auto e:cmd) print_error(e);
	}
	cout << endl;
	exit(EXIT_FAILURE);
}
void execute_cmd() {
	cout <<" inside execute command "<<endl;
	// we are assuiming that user inputs sensible commands separated by only &/&&/&&&
	bool is_background_char_exits = (find(executable_cmd.begin(), 
										executable_cmd.end(),
										background_delim) 
										!= executable_cmd.end());
	bool is_parallel_char_exits = (find(executable_cmd.begin(), 
										executable_cmd.end(),
										parallel_delim) 
										!= executable_cmd.end());
	bool is_series_char_exits = (find(executable_cmd.begin(), 
									executable_cmd.end(),
									series_delim) 
									!= executable_cmd.end());

	// only one of the above will exists at one time
	vector<string> commands[100];
	// parse the commands one by one and store inside the array commands
	
	
	int command_count = 0;
	//cout <<"xxxxxxxx : "<<executable_cmd.size() << endl;
	bool at_least_one = false;
	for(int i = 0;i<(int)(executable_cmd.size());i++) {
		cout <<"ji "<<executable_cmd[i] <<endl;
		if(!is_operator(executable_cmd[i])) {
			at_least_one = true;
			//cout <<"fuck"<<endl;
			commands[command_count].push_back(executable_cmd[i]);
		}else {
			command_count++;
		}
	}
	
	if(at_least_one && !is_background_char_exits) {
		command_count++;
	}
	//cout <<" no of commands : "<<command_count <<endl;
	if(command_count == 0) {
		//cout << "ccccccccccc " <<endl;
		return;
	}
	if(is_series_char_exits) { 	// these will be foreground commands
								// for example ls -all && ./a.out && ps && htop
								// here we have a total of 4 commands separated by &&
		cout <<" xx "<<endl;
		for(int i = 0;i<command_count;i++) {
			int status;
			pid_t pid = fork();
			if(pid == 0) {
				start_single_cmd(commands[i]);
			}else {
				do {
					waitpid(pid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
			print_info("+");
			print_info(command_to_string(commands[i]) + " completed !");
		}
		return;
	}else if(is_parallel_char_exits) {
		cout <<" yy "<<endl;
		for(int i = 0;i<command_count;i++) {
			pid_t pid = fork();
			active_pids.insert(pid);			// this pid is stored now
			if(pid == 0) {
				signal(SIGINT,SIG_IGN); 		// so this child will be irresponsive to the ctrl+c press
				start_single_cmd(commands[i]);
			}
			// no need to wait 
			pid_to_name[pid] = command_to_string(commands[i]); // link this pid to the process name or command 
		}		
	}else if(is_background_char_exits) {

		
		print_info("inside background if clause ");
		
		pid_t pid = fork();
		active_pids.insert(pid);			// this pid is stored now
		if(pid == 0) {
			signal(SIGINT,SIG_IGN); 		// so this child will be irresponsive to the ctrl+c press
			start_single_cmd(commands[0]);  // because here we will have only a single command
		}
		// no need to wait 
		pid_to_name[pid] = command_to_string(commands[0]); // link this pid to the process name or command

	}else if(command_count) { // only single command without any operator
		int status;
		pid_t pid = fork();
		if(pid == 0) {
			start_single_cmd(commands[0]);
		}else {
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		print_info("+");
		print_info(command_to_string(commands[0]) + " completed !");
	}
}

int main() {
	signal(SIGINT,SIG_IGN);
	signal(SIGCHLD,sigchld_handler);
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