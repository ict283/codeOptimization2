// For review purposes only! Does not represent the actual solution!

#include "toDoList.h"

ToDoList::ToDoList()
{

}

ToDoList::~ToDoList()
{

}

void ToDoList::run()
{
        store(read("to_do_data.txt"));

        string dateInput; //eg."5.4.21"
        string taskNoInput; //eg."3"

        cout<<"Enter date: ";
        cin>>dateInput;
        cout<<"Enter task no: ";
        cin>>taskNoInput;

        display(dateInput,taskNoInput);
}

string ToDoList::read(const string fileName)
{
        ifstream infile (fileName);

        if(!infile.is_open())
        {
                cout<<"Error: File Not Found - "<<fileName<<endl;
                return NULL;
        }

        string fileStreamData;
        getline(infile, fileStreamData);
        return fileStreamData;

}

void ToDoList::store(string fileStreamData)
{
        istringstream stringStream {fileStreamData}; //stringify

        string item="";
        string taskId="";
        string taskDate="";
        int taskNum=1;

        while (getline(stringStream,item,','))
        {
                if(item[0]=='#')
                {
                        taskDate= item.substr(1,item.length());
                        taskNum =1;
                }
                else
                {
                        Task task;
                        task.taskId = taskDate+"."+to_string(taskNum++);
                        task.taskDescription = item;
                        taskDatabase.insert(pair<string, Task>(task.taskId, task));
                }
        }
}

void ToDoList::display()
{
        map<string, Task> :: iterator itr;

        for(itr=taskDatabase.begin(); itr!=taskDatabase.end(); ++itr)
        {
                cout<<setw(10)<<setfill(' ')<<left;
                cout<<(itr->first)<<" - "<<(itr->second).taskDescription<<endl; //first = key , second = value
        }
}

void ToDoList::display(string date, string taskNo)
{
        string taskId = date+"."+taskNo;
        map<string,Task>:: const_iterator itr = taskDatabase.find(taskId);
        cout<<setw(10)<<setfill(' ')<<left;
        cout<<(itr->first)<<" - "<<(itr->second).taskDescription<<endl;
}
