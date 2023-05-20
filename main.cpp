#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee{
protected:
	string Name;
	int Id;
	int MonthlyBudget;
public:
	Employee(string name, int id, int monthlybudget){
		Name = name;
		Id = id;
		MonthlyBudget = monthlybudget;
	}
	
	void setName(string name){
		Name = name;
	}
	
	void setId(int id){
		Id = id;
	}
	
	void setMonthlybudget(int monthlybudget){
		MonthlyBudget = monthlybudget;
	}
	
	string getName(){
		return Name;
	}
	
	int getId(){
		return Id;
	}
	
	int getMonthlybudget(){
		return MonthlyBudget;
	}


};

class ElectricalEngineer : public Employee{
private:
	bool SafetyAtWork;
public:
	ElectricalEngineer(string name, int id, int monthlybudget, bool safetyatwork)
	:Employee(name, id, monthlybudget){
		SafetyAtWork = safetyatwork;
	}
	
	
	
	void setSafetyAtWork(bool safetyatwork){
		SafetyAtWork = safetyatwork;
	}
	
	
	
	bool setSafetyAtWork(){
		return SafetyAtWork;
	}
	
	
	
};

class CivileEngineer : public Employee{
private:
	int AllowanceDueToHazardsAtWork;
public:
	CivileEngineer(string name, int id, int monthlybudget, int allowanceduetohazardsatwork)
	:Employee(name, id, monthlybudget){
		AllowanceDueToHazardsAtWork = allowanceduetohazardsatwork;
	}
	

	void setAllowanceDueToHazardsAtWork(int allowanceduetohazardsatwork){
		AllowanceDueToHazardsAtWork = allowanceduetohazardsatwork;
	}
	
	
	int getAllowanceDueToHazardsAtWork(){
		return AllowanceDueToHazardsAtWork;
	}	
};

int spendOn(int monthlyBudget){
	int a, b, c, d, e;
	cout << "How much you spend on food($): ";
	cin >> a;
	cout << "How much you spend on shopping($): ";
	cin >> b;
	cout << "How much you spend on fuel($): ";
	cin >> c;
	cout << "How much you spend on utilities($): ";
	cin >> d;
	
	fstream File;
	File.open("Budget.txt", ios::app);
	if(File.is_open()){
		File << "Food: " << a << endl;
		File << "Shopping: " << b <<endl;
		File << "Fuel:" << c << endl;
		File << "Utilities:" << d << endl;  
		e = a + b + c + d;
		File << "You spend: " << e << "$. Your saving are: " << monthlyBudget - e << "$ this month" << endl;
		File.close();
	}
}


int main() {
	
	ElectricalEngineer employee1 = ElectricalEngineer("Emina", 5255, 2000, 1);
	CivileEngineer employee2 = CivileEngineer("Irma", 5622, 2500, 100);
	
	int option;
	
	cout << "1. Electrical Engineer " << endl;
	cout << "2. Civile Engineer " << endl;
	cout << "What kind of engeneer are you?: " ;
	cin >> option;
	
	if(option == 1){
		string Name;
		int Id;
		int MonthlyBudget;
		bool SafetyAtWork;
		
		cout << "Your name: ";
		cin >> Name;
		employee1.setName(Name);
		cout << "Your id: ";
		cin >> Id;
		employee1.setId(Id);
		cout << "Your Monthly Budget: ";
		cin >> MonthlyBudget;
		employee1.setMonthlybudget(MonthlyBudget);
		cout << "Are you safe at work 1(Y)/0(N): ";
		cin >> SafetyAtWork;
		employee1.setSafetyAtWork(SafetyAtWork);
		
		
	    fstream File;
      	File.open("Budget.txt", ios::out);
     	if(File.is_open()){
		File << employee1.getName() << " your montly budget is: " << employee1.getMonthlybudget() << "$\n " << endl;
	    }File.close();
	    
	    spendOn(employee1.getMonthlybudget());
		
	}else if(option == 2){
		string Name;
		int Id;
		int MonthlyBudget;
		int AllowanceDueToHazardsAtWork;
		
		cout << "Your name: ";
		cin >> Name;
		employee2.setName(Name);
		cout << "Your id: ";
		cin >> Id;
		employee2.setId(Id);
		cout << "Your Monthly Budget($): ";
		cin >> MonthlyBudget;
		employee2.setMonthlybudget(MonthlyBudget);
		cout << "How much are you paid for the work risk($): ";
		cin >> AllowanceDueToHazardsAtWork;
		employee2.setAllowanceDueToHazardsAtWork(AllowanceDueToHazardsAtWork);
		
		
		fstream File;
      	File.open("Budget.txt", ios::out);
     	if(File.is_open()){
		File << employee2.getName() << " your montly budget is: " << employee2.getMonthlybudget() + employee2.getAllowanceDueToHazardsAtWork() << "$\n" << endl;
	}File.close();
	
	spendOn(employee2.getMonthlybudget() + employee2.getAllowanceDueToHazardsAtWork());

	}else{
		cout << "Not an option!" << endl;
	}
	
	
	
	
	

	return 0;
}
