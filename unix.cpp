#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Unix {
	string name;
	string parent;
	string type;
};

string current = "root";

//Directory commands
void mkdir(string s, string p);
void mkfile(string s, string p);
void mv(string s);
void rm(string s);
void cd(string s);
void ls(string s);

vector<Unix> types;

int main()
{

	string filename;
	string line;
	string command;

	char c;

	int count = 0;
	int pos;

	vector<string> commands;

	cout << "Enter the name of the file that you wish to use: " << endl;
	getline(cin , filename);

	ifstream fin;
	fin.open(filename.c_str());

	if(fin.is_open())
	{
		types.push_back(Unix());

		//Initializes the Root
		types[0].name = "root";
		types[0].parent = "none";
		types[0].type = "directory";

		while(getline(fin, line))
		{
			commands.push_back(line);
		}
		for(int i = 0; i<commands.size(); i++)
		{

			//Get the command that is being requested
			line = commands.at(i);
			pos = line.find(" ");
			command = line.substr(0, pos);

			//Decides which command is being asked in the code
			if(command == "mkdir")
			{
				mkdir(line, current);
				//cout << "Current Directory: " << current << endl;
			}
			else if(command == "mkfile")
			{
				mkfile(line, current);
				//cout << "Current Directory: " << current << endl;
			}
			else if(command == "mv")
			{
				mv(line);
			}
			else if(command == "rm")
			{
				rm(line);
			}
			else if(command == "cd")
			{
				cd(line);
				cout << "Current Directory: " << current << endl;
			}
			else if(command == "ls")
			{
				ls(line);
				//cout << "Current Directory: " << current << endl;
			}
			else
			{
				cout << "not a valid command" << endl;
			}
		}
	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	return 0;
}


void mkdir(string s, string p)
{
	int pos;
        int spot;

        pos = s.find(" ");
        types.push_back(Unix());
        spot = types.size() - 1;
        types[spot].name = s.substr(pos+1,s.length());
        types[spot].type = "directory";
        types[spot].parent = p;

}

//Make file
void mkfile(string s, string p)
{
	int pos;
	int spot;

	pos = s.find(" ");
	types.push_back(Unix());
	spot = types.size() - 1;
	types[spot].name = s.substr(pos+1,s.length());
	types[spot].type = "file";
	types[spot].parent = p;
}

//Change directory
void cd(string s)
{
	int pos;

	pos = s.find(" ");
	current = s.substr(pos+1, s.length());
}

//Print function
void ls(string s)
{
	int pos;
	string a;

	pos = s.find(" ");
	for(int i = 0; i < types.size(); i++)
	{
		if(types[i].parent == current)
		{
			cout << types[i].name << endl;
		}
	}
}

void mv(string s)
{
	int pos;

	string one;
	string two;

	pos = s.find(" ");
	one = s.substr(pos+1,s.rfind(" ") - 1);

	pos = s.rfind(" ");
	two = s.substr(pos+1, s.length());

	for(int i = 0; i < types.size();i++)
	{
		if(types[i].name == one && types[i].parent != two)
		{
			types[i].parent = two;
		}
	}

}

//Remove function
void rm(string s)
{
	int pos;
	string a;

	pos = s.find(" ");
	a = s.substr(pos+1, s.length());
	for(int i = 0; i < types.size();i++)
	{
		if(types[i].name == a)
		{
			if(types[i].type == "directory")
			{
				for(int j = 0; j < types.size();j++)
				{
					if(types[j].parent == a)
					{
						types.erase(types.begin()+j);
					}
				}
				current = types[i].parent;
				types.erase(types.begin()+i);
			}
			else
			{
				types.erase(types.begin()+i);
			}
		}
		else
		{
			cout << "the chosen file or directory does not exist" << endl;
		}
	}
}
