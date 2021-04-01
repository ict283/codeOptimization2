// For review purposes only! Does not represent the actual solution!

#ifndef toDoList_h
#define toDoList_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include <map>

using namespace std;

struct Task
{
        string taskId;
        string taskDescription;
};


class ToDoList
{

public:

ToDoList();

~ToDoList();

void run();

string read(const string fileName);

void store(string fileStreamData);

void display();

void display(string date, string taskNo);

private:

map<string,Task> taskDatabase; //Key-Value store

};

#endif /* toDoList_h */
