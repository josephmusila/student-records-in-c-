#include <iostream>
#include<fstream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

using namespace std;
class add_records{
private:
    char name[19];
    char index[10];
    float gpa;

public:
    void read_data();
    void show_data();
    void  add_data();
    void  write_rec();


};

void add_records::add_data()
{

    cout<<"enter your name"<<endl;
    cin>>name;
    cout<<"enter your index"<<endl;
    cin>>index;
    cout<<"enter your gpa;"<<endl;
    cin>>gpa;
}
void add_records::show_data()
{

    cout<<"you name is: "<<name<<endl;
    cout<<"your index is: "<<index<<endl;
    cout<<"your gpa is  : "<<gpa<<endl;
    cout<<"------------------------------------"<<endl;
}
void add_records::write_rec(){
    ofstream outfile;
    outfile.open("record.txt" , ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this),sizeof(*this));
    outfile.close();
}
void add_records::read_data(){
    ifstream infile;
    infile.open("record.txt",ios::binary);
    if(!infile)
    {

        cout<<"error opening file! file not found"<<endl;
        return;
    }
    cout<<"\n********Data from file*********"<<endl;
    while(infile.eof()){
        if(infile.read(reinterpret_cast<char *>(this),sizeof(*this))>0){
           show_data();
           }
    }
    infile.close();

}
int main()
{
    add_records A;
    int choice;
    cout<<"*******Student information system***********"<<endl;
    while(true){
        cout<<"Select an option below"<<endl;
        cout<<"\n\t1-->Add record to file"<<endl;
        cout<<"\n\t2-->Show record from file"<<endl;
        cout<<"\n\t3-->quit"<<endl;
        cout<<"Enter your Choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:
            A.add_data();
            break;
        case 2:
            A.show_data();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"please enter a valid choice"<<endl;
            exit(0);
        }
    }
    system("pause");




    return 0;
}
