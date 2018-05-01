#include<iostream>
#include<fstream>

using namespace std;

void add()
{
    ofstream fin;
    ///open a file
    fin.open("task.txt",ios_base::app);
    string task;
    cout << "Enter a task: (name & description: date:): ";
    getline(cin, task);
    fin << task << endl;
    fin.close();
}

void show()
{
    ifstream fin;
    string str;
    fin.open("task.txt");
    while(getline(fin,str))
    {
        cout << str << endl;
    }
    fin.close();

}

void deleteTask()
{
    string str1, str2;
    cout << "Task for delete: (name & description: date:) :";
    getline(cin,str1);
    ofstream fout;
    ifstream fin;
    fin.open("task.txt");
    fout.open("temporary.txt");
    while(getline(fin, str2))
    {
        if(str1 == str2)
            continue;
        fout << str2 << endl;
    }
    fin.close();
    fout.close();
    fout.open("task.txt");
    fin.open("temporary.txt");
    while(getline(fin, str2))
    {
        fout << str2 << endl;
    }
    fin.close();
    fout.close();
}

int main()
{
    int option;
    while(true)
    {
        cout << "1 add\n2 show\n3 delete\n4 exit\n";
        cout << "Choose a option 1-4: ";
        cin >> option;
        cin.ignore();
        if(option == 1)
            add();
        else if(option == 2)
            show();
        else if(option == 3)
            deleteTask();
    }
    return 0;
}