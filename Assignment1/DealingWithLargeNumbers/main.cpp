/*1a. Dealing with Large Numbers even beyond the range of long long int*/ 
#include <iostream> 
#include<string> 
#include <fstream> 

using namespace std;
 
void reverese_string(string &s) 
{ 
    int j=s.length(); 
    for(int i=0;i<j/2;i++) 
    { 
        char ch=s[j-i-1]; 
        s[j-i-1]=s[i]; 
        s[i]=ch; 
    } 
} 
 
bool check_num(string s)//to check whether the given sequence is a valid number or not 
{ 
    int i=0; 
    while(i<s.length()) 
    { 
        if(s[i]>57 || s[i]<48) 
            return false; 
        i++; 
    } 
    return true; 
} 
 
string largeAdd(string num1,string num2) 
{ 
    string sum; 
 
    int i=num1.length()-1; 
    int j=num2.length()-1; 
    int carry=0; 
 
 
    while(i>-1 || j>-1) 
    { 
        if(i>-1 && j>-1) 
        { 
            int digit_sum=num1[i]-'0'+num2[j]-'0'+carry;//computing digit wise summation 
            if(digit_sum>=10)//if there is a carry 
            { 
                carry=1; 
                sum.push_back(int(digit_sum-10)+48); 
            } 
            else { 
                carry = 0; 
                sum.push_back(int(digit_sum)+48); 
            } 
            i--; 
            j--; 
        } 
        else if (i==-1)//if num2 is larger than num1 
        { 
            int digit_sum=num2[j]-'0'+carry; 
            if(digit_sum>=10) 
            { 
                carry=1; 
                sum.push_back(int(digit_sum-10)+48); 
            } 
            else { 
                carry = 0; 
                sum.push_back(int(digit_sum)+48); 
            } 
            j--; 
        } 


        else//if num1 is larger than num2 
        { 
            int digit_sum=num1[i]-'0'+carry; 
            if(digit_sum>=10) 
            { 
                carry=1; 
                sum.push_back(int(digit_sum-10)+48); 
            } 
            else { 
                carry = 0; 
                sum.push_back(int(digit_sum)+48); 
            } 
            i--; 
        } 
 
    } 
    if (carry==1) 
        sum.push_back('1'); 
 
    reverese_string(sum); 
    return sum; 
} 
 
 
int main() { 
 
    ofstream new_file("sum.txt",ios::out);//opening a new file for writing 
    while(1) 
    {
        int choice; 
 
        cout<<"PLEASE CHOOSE B/W (1,2):::::::::::::::"<<endl; 
        cout<<"1.Summation of two numbers"<<endl<<"2.Quit"<<endl; 
        cin>>choice; 
        switch(choice) 
        { 
            case(1): 
            { 
                string num1,num2; 
                cout<<"Enter the 1st no. :"<<endl; 
                cin>>num1; 
                cout<<"Enter the 2nd no. :"<<endl; 
                cin>>num2; 
                if(!check_num(num1) || !check_num(num2))//checking whether the given numbers are valid or not 
                { 
                    cout<<"Invalid number input!!!!try again!!"<<endl; 
                    break; 
                } 
                /*calling summation function which returns a string*/ 
                cout<<endl<<"Summation of your given numbers : "<<largeAdd(num1,num2)<<endl<<endl; 
                /*inserting sum value using insertion operator in the new_file*/ 
                new_file<<"Summation of your given numbers : "<<largeAdd(num1,num2)<<endl; 
                continue; 
            } 
            case(2): 
                break; 
            default: 
                cout<<"Invalid choice try again!!!!"<<endl; 
                continue; 
        } 
        new_file.close(); 
        cout<<"Your summation output has been saved to sum.txt"<<endl; 
        return 0; 
    } 
}