#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    int num1;
    int num2;
    int num_rand;
    cout<<"Please enter the range of two numbers to generate random numbers.\n";
    cout<<"#1: ";
    cin>>num1;
    cout<<"#2: ";
    cin>>num2;
    cout<<"How many random numbers in between would you like? ";
    cin>>num_rand;

    mt19937 randomGenerator(time(NULL)); //random type variable with default seed
    uniform_int_distribution<int> random(num1, num2);
    //assuming numbers are entered correctly and num1 < num2
    cout<<"\nFor random integers:\n";
    for(int i=0; i<num_rand; i++){
        cout<< "Your random integer #"<<i<<" is: "<<random(randomGenerator)<<endl;
    }

    uniform_real_distribution<float> decimal(num1, num2);

    cout<<"\nFor random decimals:\n";

    for(int i=0; i<num_rand; i++){
        cout<< "Your random decimal #"<<i<<" is: "<<decimal(randomGenerator)<<endl;
    }

    //system("PAUSE");
    return 0;
}
