// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ph1_Employee.h"
#include "ph2_Employee.h"
#include "ph3_Employee.h"
#include "ph4_Employee.h"

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
	{
		ph2::CEngineer oEngineer("Jan", "Kowalski", ph2::CEmployee::ENGINEER, 3750.00);
		cout << oEngineer << endl;

		ph2::CSalesman oSalesman("Piotr", "Malinowski", ph2::CEmployee::SALESMAN, 2250.00);
		oSalesman.SetCommission(670.00);
		cout << oSalesman << endl;

		auto pManager = make_unique<ph2::CManager>("Maciek", "Nowak", ph2::CEmployee::MANAGER);
		pManager->SetMonthlySalary(5000.00);
		pManager->SetBonus(3000.00);
		cout << *pManager << endl;
	}
	{
		ph3::CEngineer oEngineer("Jan", "Kowalski", 3750.00);
		cout << oEngineer << endl;

		ph3::CSalesman oSalesman("Piotr", "Malinowski", 2250.00);
		oSalesman.SetCommission(670.00);
		cout << oSalesman << endl;

		auto pManager = make_unique<ph3::CManager>("Maciek", "Nowak");
		pManager->SetMonthlySalary(5000.00);
		pManager->SetBonus(3000.00);
		cout << *pManager << endl;
	}
	{
		ph4::CEngineer oEngineer("Jan", "Kowalski", 3750.00);
		cout << oEngineer << endl;

		ph4::CSalesman oSalesman("Piotr", "Malinowski", 2250.00);
		oSalesman.SetCommission(670.00);
		cout << oSalesman << endl;

		auto pManager = make_unique<ph4::CManager>("Maciek", "Nowak");
		pManager->SetMonthlySalary(5000.00);
		pManager->SetBonus(3000.00);
		cout << *pManager << endl;
	}

	return 0;
}

