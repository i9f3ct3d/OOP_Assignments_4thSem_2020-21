/*1b) Displaying number patterns*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int n;
    cout<<"Enter the number for your desired pattern ? "<<endl;
    cin>>n;
    cout<<":::::::::::YOUR DESIRED PATTERN:::::::::::"<<endl<<endl;

    for(int i=1;i<=n;i++)
    {
        int j;
        cout<<setw(i);
        for( j=i;j<=n;j++)
        {
            cout<<j;
        }
        for(int k=j-2;k>=i;k--)
        {
            cout<<k;
        }
        cout<<endl;
    }


    for(int i=1;i<n;i++)
    {
        int j;
        cout<<setw(n-i);
        for( j=n-i;j<=n;j++)
        {
            cout<<j;
        }
        for(int k=j-2;k>n-1-i;k--)
        {
            cout<<k;
        }
        cout<<endl;
    }
    return 0;
}