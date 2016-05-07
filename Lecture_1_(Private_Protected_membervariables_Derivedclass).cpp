#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Base class
class Employee{
    protected://accessible by derived class (if private only within Employee)
        string name; //only accessible within Employee otherwise change it to protected
        double pay;
    public:
        Employee(){ //default constructor
            name = "";
            pay = 0;
        }
        Employee(string empName, double payRate){ //proper constructor
            name = empName;
            pay = payRate;

        }
        //class methods
        string getName(){
            return name;
        }
        void setName(string empName){
            name = empName;
        }
        double getPay(){
            return pay;
        }
        void setPay (double payRate){
            pay = payRate;
        }
        string toString(){
            stringstream stm;
            stm << name << ": " <<pay;
            return stm.str();
        }
        double grossPay(int hours){
            return hours * pay;
        }
};

//Derived class (manager in this case derives the employee class public attributes such as name and payrate)
class Manager : public Employee{
    private:
        bool salaried;

    public:
        Manager(string name, double payRate, bool isSalaried) : Employee(name, payRate)
        { // call to base constructor
            salaried = isSalaried;
        }
        bool getSalaried(){
            return salaried;
        }

        double grossPay(int hours){ //pays different to regular employee, different method than to Employee Class!
            if(salaried){
                return pay;
            }
            else{
                return pay * hours;
            }
        }

        string toString(){
            stringstream stm;
            string salary;
            if(salaried){
                salary = "Salaried";
            }
            else{
                salary = "Hourly";
            }
            stm << name << ": $" <<pay << " : "<<salary<<endl;
            return stm.str();
        }

};


int main()
{

//    Employee emp1("Jane Smith", 35000);
//    Employee emp2("Bill Brown", 32000);
//    cout<<emp1.toString() <<endl;
//    cout<<emp2.toString() <<endl;

    Employee emp1("Vincent Z", 15.00);
    cout<<"Employee name: " <<emp1.getName()<<endl;
    cout<<"Employee pay rate: "<<emp1.getPay()<<endl;
    cout<<"Employee gross pay: $"<<emp1.grossPay(40)<<endl;
    Manager emp2("Vince's Manager", 1500, true);
    cout<<"Employee 2 name: " <<emp2.getName()<<endl;
    cout<<"Employee 2 pay rate: "<<emp2.getPay()<<endl;
    cout<<"Employee 2 salaried? "<<emp2.getSalaried()<<endl;
    cout<<emp2.toString();
    cout<<"Employee 2 gross pay: $"<<emp2.grossPay(40)<<endl;


    return 0;
}
