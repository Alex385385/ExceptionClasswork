#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
   string employeeName;
   int employeeNum;
   string hireDate;
public:
   class InvalidEmployeeNumber
   {};
   Employee()
   {
      employeeName = "";
      employeeNum = 0;
      hireDate = "";
   }
   Employee(string name, int num, string date)
   {
      employeeName = name;
      employeeNum = num;
      hireDate = date;
   }
   void setEmployeeName(string n)
   {
      employeeName = n;
   }
   void setEmployeeNum(int n)
   {
      if(n > 0 && n <= 9999)
      {
         employeeNum = n;
      }
      else
      {
         throw InvalidEmployeeNumber();
      }
   }
   void setHireDate(string n)
   {
      hireDate = n;
   }
   string getEmployeeName()
   {
      return employeeName;
   }
   int getEmployeeNum()
   {
      return employeeNum;
   }
   string getHireDate()
   {
      return hireDate;
   }
};

class ProductionWorker : public Employee
{
private:
   int shift;
   double hourlyPay;
public:
   class InvalidShift
   {};
   class InvalidPayRate
   {};
   ProductionWorker() : Employee()
   {
      shift = 0;
      hourlyPay = 0;
   }
   ProductionWorker(string name, int num, string date, int shi, double pay) : Employee(name, num, date)
   {
      shift = shi;
      hourlyPay = pay;
   }
   void setShift(int n)
   {
      if(n == 1 || n == 2)
      {
         shift = n;
      }
      else
      {
         throw InvalidShift();
      }
   }
   void setHourlyPay(double n)
   {
      if(n >= 0)
      {
         hourlyPay = n;
      }
      else
      {
         throw InvalidPayRate();
      }
   }
   int getShift()
   {
      return shift;
   }
   double getHourlyPay()
   {
      return hourlyPay;
   }

   void print()
   {
      cout << "Name: " << getEmployeeName() << endl;
      cout << "Employee Number: " << getEmployeeNum() << endl;
      cout << "Date hired: " << getHireDate() << endl;
      cout << "Shift: " << getShift() << endl;
      cout << "Hourly pay rate: $" << getHourlyPay() << endl;
   }
};

int main()
{
   string name, date;
   int number, shift;
   double pay;
   bool valid = true;

   ProductionWorker worker;

   cout << "Enter Name: ";
   cin >> name;
   worker.setEmployeeName(name);

   cout << "Enter Employee Number: ";
   cin >> number;
   while(valid)
   {
      try
      {
         worker.setEmployeeNum(number);
         valid = false;
      }
      catch(ProductionWorker::InvalidEmployeeNumber)
      {
         cout << "Employee number must be between 1 - 9999, enter again: ";
         cin >> number;
      }
   }
   valid = true;

   cout << "Enter date hired: ";
   cin >> date;
   worker.setHireDate(date);

   cout << "Enter shift: ";
   cin >> shift;
   while(valid)
   {
      try
      {
         worker.setShift(shift);
         valid = false;
      }
      catch(ProductionWorker::InvalidShift)
      {
         cout << "Shift is either 1 for day or 2 for night, enter again: ";
         cin >> shift;
      }
   }

   valid  = true;

   cout << "Enter hourly pay rate: ";
   cin >> pay;
   while(valid)
   {
      try
      {
         worker.setHourlyPay(pay);
         valid = false;
      }
      catch(ProductionWorker::InvalidPayRate)
      {
         cout << "Pay rate can't be negative, enter again: ";
         cin >> pay;
      }
   }
   cout << endl;

   worker.print();

   return 0;
}
