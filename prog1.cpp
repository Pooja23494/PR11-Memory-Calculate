#include<iostream>
#include<vector>
using namespace std;

template <typename T1, typename T2> 
class MemoryCalculate{
    public:
        vector<int> v1;
        vector<string> v2;
        T1 Id;
        T2 Name;

        MemoryCalculate(int size)
        {
            for(int i=0;i<size;i++)
            {
                cout<<"Enter Student Id ["<<i<<"]: ";
                cin>>this->Id;
                v1.push_back(this->Id);
                cout<<"Enter Student Name ["<<i<<"]: ";
                cin>>this->Name;
                v2.push_back(this->Name);
            }
        }
        void displayStudent()
        {
            cout<<"Student List"<<endl;
            cout<<"-----------------"<<endl;
            for(int i=0;i<v1.size();i++)
            {
                cout<<"Student Id ["<<i<<"]: "<<v1.at(i)<<endl;
                cout<<"Student Name ["<<i<<"]: "<<v2.at(i)<<endl;
            }
        }
        void addStudent(T1 Id, T2 Name)
        {
            v1.push_back(Id);
            v2.push_back(Name);
        }
        void removeStudent(T1 Id)
        {
            for(int i=0;i<v1.size();i++)
            {
                if(v1[i]==Id)
                {
                    v1.erase(v1.begin()+i);
                    v2.erase(v2.begin()+i);
                    cout<<"Remove student by Id ["<<Id<<"] successfully."<<endl;
                }
            }
        }
        void serachStudent(T1 Id)
        {
            for(int i=0;i<v1.size();i++)
            {
                if(v1[i]==Id)
                {
                    cout<<"Student Id ["<<i<<"]: "<<v1.at(i)<<endl;
                    cout<<"Student Name ["<<i<<"]: "<<v2.at(i)<<endl;
                }
            }
        }
};
int main(){

    int size,choice,Id;
    string Name;
    cout<<"Enter size of vector: ";
    cin>>size;

    MemoryCalculate<int,string> obj(size);

    do{
        cout<<endl;
        cout<<"Enter 1 for Add Student to a list. "<<endl;
        cout<<"Enter 2 for Display the list of students."<<endl;
        cout<<"Enter 3 for Remove a student from the list by Id."<<endl;
        cout<<"Enter 4 for Search student by Id."<<endl;
        cout<<"Enter 0 for Exit."<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter Student Id: ";
                cin>>Id;
                cout<<"Enter Student Name: ";
                cin>>Name;
                obj.addStudent(Id,Name); 
                break;
            case 2:
                obj.displayStudent(); 
                break;
            case 3:
                cout<<"Enter Student Id for Remove from the list: ";
                cin>>Id;
                obj.removeStudent(Id);
                break;
            case 4:
                cout<<"Enter Student Id for Serach from the list: ";
                cin>>Id; 
                obj.serachStudent(Id);
                break;
            case 0:
                cout<<"Exit."<<endl; 
                break;
            default:
                cout<<"Wrong choice!"<<endl; 
                break;
        }

    }while(choice!=0);
    return 0;
}