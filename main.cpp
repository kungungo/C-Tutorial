#include <iostream>
#include <cstdlib>
#include <ctime> //time function included

using namespace std;

void random_gen(){

    srand(time(0));
    double grades[10];
    double random;
    double total = 0;
    double average = 0;
    for(int i = 0; i<10; i++){
        random = 50 + (rand() % 50) + 0.01*(rand() % 100);
        grades[i] = random;
        total = total + grades[i];
    }

    for(int i = 0; i<10; i++){
        cout<<"Student's test #: "<<i+1<<" has a score of: "<<grades[i]<<endl;

        if(grades[i]>=90){
            cout<<"A grade, excellent!"<<endl<<endl;
        }
        else if(grades[i]>=80 && grades[i]<90){
            cout<<"B grade, well done."<<endl<<endl;
        }
        else if(grades[i]>=70 && grades[i]<80){
            cout<<"C grade, passed."<<endl<<endl;
        }
        else if(grades[i]>=60 && grades[i]<70){
            cout<<"D grade, barely passing..."<<endl<<endl;
        }
        else{
            cout<<"F grade, failed."<<endl<<endl;
        }
    }

    average = total/(sizeof(grades)/sizeof(grades[0]));

    cout<<"Student's average score on exams: "<<average<<endl;
}


int main()
{
    random_gen();
    return 0;
}
