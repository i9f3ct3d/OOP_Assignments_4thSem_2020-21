/*1b) A trigonometric function plotter*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void cos_func()//cosine wave function
{
    double s_angle{};
    double t_angle{};
    int step_length{};
    char choice;

    cout<<"Enter the starting angle in degree : "<<endl;
    cin>>s_angle;
    cout<<"Enter the terminating angle in degree : "<<endl;
    cin>>t_angle;
    cout<<"Enter the step length : "<<endl;
    cin>>step_length;
    cout<<"Enter the special character you want to be displayed in the trigonometric function : "<<endl;
    cin>>choice;

    cout<<":::::::::::YOUR DESIRED COSINE CURVE::::::::::::::"<<endl<<endl;

    for(int j=int (s_angle) ;j<=int(t_angle);j+=step_length)
    {

        int value=int(cos((j*M_PI)/180)*50);//M_PI is the pi value
        if(value>=0)
        {
            cout<<setw(55)<<setfill(' ')<<'|'<<setw(value)<<setfill(choice)<<'+'<<endl;
        }
        else
        {
            value=abs(value);
            cout<<setw(55-value)<<setfill(' ')<<'+'<<setw(value)<<setfill(choice)<<'|'<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

void expo_func()//exponential function plotter
{
    double upper_limit,lower_limit;
    int step_count;
    char choice;

    cout<<"Enter the lower limit of x ?"<<endl;
    cin>>lower_limit;
    cout<<"Enter the upper limit of x ?"<<endl;
    cin>>upper_limit;
    cout<<"Enter the step count :"<<endl;
    cin>>step_count;
    cout<<"Enter your desired character for graph :"<<endl;
    cin>>choice;

    cout<<":::::::::::YOUR DESIRED EXPONENTIAL CURVE::::::::::::::"<<endl<<endl;

    int count=0;
    for(int i=int(lower_limit);i<=int(upper_limit);i+=step_count)
    {
        int value=int(exp(i));

        if(i<0)
        {
            cout<<setw(1)<<setfill(' ')<<'|'<<setw(value+1)<<setfill('*')<<'+'<<endl;
        }
        else
        {
            if(count==0)
            {
                cout<<setw(int(exp(4))+1)<<setfill('-')<<'-'<<endl;//displaying the horizontal y axis
                count++;
            }
            cout<<setw(1)<<setfill(' ')<<'|'<<setw(value+1)<<setfill('*')<<'+'<<endl;

        }
    }


    cout<<endl;
}

int main() {
    cout<<"=================== HERE IS MY TRIGONOMETRIC FUNCTION PLOTTER ================"<<endl;
    while (1)
    {
        int choice;
        cout<<"1.Cosine Wave"<<endl<<"2.Exponential function"<<endl<<"3.Quit"<<endl;
        cin>>choice;
        switch (choice) {
            case(1):
            {
                cos_func();
                break;
            }
            case(2):
            {
                expo_func();
                break;
            }
            case(3):
            {
                return 0;
            }
            default:
                cout<<"Invalid input try again!!!!!!!"<<endl;
                break;

        }
    }
}