/*1c) Generating random numbers*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

unsigned long long int m{4294967296},a{22695477};

void myrand()
{
    time_t t=time(nullptr);
    srand(t);
    cout<<"The time as seed : "<<t<<endl;
    unsigned long int x=t;
    int count;

    cout<<"How many numbers do you wish to generate ?"<<endl;
    cin>>count;

    double x_square_mine{};
    double x_square_comp{};
    int my_rand_observer_array[5]={};//number_of_bucket=5
    int comp_rand_observer_array[5]={};//number_of_bucket=5
    double expected_value=((count/50.0)*10);
    for(int i=0;i<count;i++)
    {
        x=(x*a)%m;
        unsigned long int my_rand=x%50;
        unsigned long int comp_rand=rand()%50;

        if(my_rand && comp_rand)
        {
            if(my_rand>=1 && my_rand<=10)
                my_rand_observer_array[0]++;
            else if(my_rand>=11 && my_rand<=20)
                my_rand_observer_array[1]++;
            else if(my_rand>=21 && my_rand<=30)
                my_rand_observer_array[2]++;
            else if(my_rand>=31 && my_rand<=40)
                my_rand_observer_array[3]++;
            else if(my_rand>=41 && my_rand<=50)
                my_rand_observer_array[4]++;

            if(comp_rand>=1 && comp_rand<=10)
                comp_rand_observer_array[0]++;
            else if(comp_rand>=11 && comp_rand<=20)
                comp_rand_observer_array[1]++;
            else if(comp_rand>=21 && comp_rand<=30)
                comp_rand_observer_array[2]++;
            else if(comp_rand>=31 && comp_rand<=40)
                comp_rand_observer_array[3]++;
            else if(comp_rand>=41 && comp_rand<=50)
                comp_rand_observer_array[4]++;
        }
    }
    for(int j=0;j<5;j++)//as the number of bucket is 5
    {
        x_square_mine+=(pow(my_rand_observer_array[j]-expected_value,2))/expected_value;
        x_square_comp+=(pow(comp_rand_observer_array[j]-expected_value,2))/expected_value;
    }
    cout<<endl<<"Chi squared value for my random numbers :"<<x_square_mine<<endl;
    cout<<endl<<"Chi squared value for computer's random numbers :"<<x_square_comp<<endl;
}

int main() {
    myrand();
    return 0;
}