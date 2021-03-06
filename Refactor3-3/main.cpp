// main : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ph1_Employee.h"
#include "ph2_Employee.h"
#include "ph3_Employee.h"
#include "ph4_Employee.h"
#include "ph5_Employee.h"

int main()
{
	// Klient-aplikacja może wykorzystywać klaseę CEmployee w różny sposób.
	{
		ph1::CEmployee oEngineer("Jan", "Kowalski", ph1::CEmployee::ENGINEER, 3750.00);
		cout << oEngineer << endl;

		ph1::CEmployee oSalesman("Piotr", "Malinowski", ph1::CEmployee::SALESMAN, 2250.00);
		oSalesman.SetCommission(670.00);
		cout << oSalesman << endl;

		auto pManager = make_unique<ph1::CEmployee>("Maciek", "Nowak", ph1::CEmployee::MANAGER);
		pManager->SetMonthlySalary(5000.00);
		pManager->SetBonus(3000.00);
		cout << *pManager << endl;
	}
	// Zmiany w ph2 nie mają wpływu na wywołania.
	{
		ph2::CEmployee oEngineer("Jan", "Kowalski", ph2::CEmployee::ENGINEER, 3750.00);
		cout << oEngineer << endl;

		ph2::CEmployee oSalesman("Piotr", "Malinowski", ph2::CEmployee::SALESMAN, 2250.00);
		oSalesman.SetCommission(670.00);
		cout << oSalesman << endl;

		auto pManager = make_unique<ph2::CEmployee>("Maciek", "Nowak", ph2::CEmployee::MANAGER);
		pManager->SetMonthlySalary(5000.00);
		pManager->SetBonus(3000.00);
		cout << *pManager << endl;
	}
	// Zmiany w ph3 umożliwiają dynamiczną zmianę stanowiska. 
	{
		ph3::CEmployee oEmployee("Jan", "Kowalski", ph3::CCompanyStand::ENGINEER, 3750.00);
		cout << oEmployee << endl;
		oEmployee.SetCompanyStand(ph3::CCompanyStand::MANAGER);
		oEmployee.SetMonthlySalary(5000.00);
		oEmployee.SetBonus(3000.00);
		cout << oEmployee << endl;
	}
	{
		ph4::CEmployee oEmployee("Jan", "Kowalski", ph4::CCompanyStand::EStand::eEngineer, 3750.00);
		cout << oEmployee << endl;
		oEmployee.SetCompanyStand(ph4::CCompanyStand::EStand::eManager);
		oEmployee.SetMonthlySalary(5000.00);
		oEmployee.SetBonus(3000.00);
		cout << oEmployee << endl;
	}
	{
		ph5::CEmployee oEmployee("Jan", "Kowalski", ph5::CCompanyStand::EStand::eEngineer, 3750.00);
		cout << oEmployee << endl;
		oEmployee.SetCompanyStand(ph5::CCompanyStand::EStand::eManager, 6500.00);
		oEmployee.SetBonus(3000.00);
		cout << oEmployee << endl;
	}
}