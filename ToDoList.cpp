#include<iostream>
#include<fstream>

using namespace std;

void add()
{
    ofstream fin;
    fin.open("task.txt",ios_base::app);
    string task;
    cout << "Enter a task: (name & description: date:): ";
    getline(cin, task);
    fin << task << endl;
    fin.close();
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
    }
}