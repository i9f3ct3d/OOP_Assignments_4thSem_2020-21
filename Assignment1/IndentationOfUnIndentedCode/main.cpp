/*1b) Indentation of an unindented code*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void indent()
{
    string s;
    string s_display;
    string file_name;
    int tab_counter=0;

    ifstream old_file;//opening a file for reading 

    while(1)//terminates when I have a valid file directory 
    {
        cout<<"Enter the file name in (.txt) format :"<<endl;
        cin>>file_name;//storing the name of the non-indented file 


        old_file= basic_ifstream<char>(file_name,ios::in);//type casting to basic_ifstream<char> 

        if(!old_file)//executes when file does not exist at all 
        {
            cout<<"Sorry you are trying to access a invalid file!!!!try again!!!!"<<endl;
            file_name.erase();
            continue;
        }
        break;
    }
    cout<<"DISPLAYING YOUR NON-INDENTED CODE:::::::::::"<<endl<<endl;

    while (!old_file.eof())//until it reaches the end of file 
    {
        getline(old_file,s_display);//extracting a whole line from old_file to s_display string 
        cout<<s_display<<endl;
    }

    old_file.clear();//clearing eof flag 
    old_file.seekg(0);//seeking to first index of file which is 0 in that case 

    ofstream new_file("indented.cpp",ios::out);//opening a file in write mode 

    cout<<endl<<"DISPLAYING YOUR MODIFIED INDENTED CODE:::::::::::"<<endl<<endl;


    while(!old_file.eof())
    {
        getline(old_file,s);//extracting a whole line from old_file to s string 
        if(s=="}")
        {
            tab_counter--;
        }
        for(int i=0;i<tab_counter;i++)
        {
            new_file<<"\t";//inserting tab escape sequence in the new file 
            cout<<"\t";//printing it in the console 
        }

        if(s.find('{')!=string::npos)
            tab_counter++;
        new_file<<s<<endl;//inserting the whole line in the new file 
        cout<<s<<endl;//printing the whole line in console 

    }

    old_file.close();//closing old file 
    new_file.close();//closing new file 
    cout<<endl<<"YOUR CODE HAS BEEN INDENTED AND SAVED TO indented.cpp file"<<endl;
}

int main(){
    indent();//calling indent function 
    return 0;
} 