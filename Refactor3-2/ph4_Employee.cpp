#include "stdafx.h"
#include "ph4_Employee.h"

ph4::CEmployee::CEmployee(const string& strFirstName,
	const string& strLastName,
	double dMonthlySalary /*= 0.0*/) :
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	m_dMonthlySalary(dMonthlySalary)/**,**/
{
}

ph4::CEmployee::~CEmployee()
{
}

ostream& ph4::operator <<(ostream& os, const ph4::CEmployee& oEmployee)
{
	os << "First name: " << oEmployee.GetFirstName() << endl;
	os << "Last name: " << oEmployee.GetLastName() << endl;
	os << "Company stand: " << oEmployee.GetCompanyStandAsString() << endl;
	os << "Salary: " << put_money(oEmployee.GetPayAmount(), true) << endl;

	return os;
}


/* CEngineer class definition ****************************************************/
ph4::CEngineer::CEngineer(const string& strFirstName,
	const string& strLastName,
	double dMonthlySalary /*= 0.0*/) :
	CEmployee(strFirstName, strLastName, dMonthlySalary)
{
}

ph4::CEngineer::~CEngineer()
{
}

double ph4::CEngineer::GetPayAmount() const
{
	return GetMonthlySalary();
}

string ph4::CEngineer::GetCompanyStandAsString() const
{
	static const string STR_ENGINEER = "Engineer";

	return STR_ENGINEER;
}


/* CSalesman class definition ****************************************************/
const double ph4::CSalesman::BASIC_COMMISSION = 500;

ph4::CSalesman::CSalesman(	const string& strFirstName,
							const string& strLastName,
							double dMonthlySalary /*= 0.0*/) :
	CEmployee(strFirstName, strLastName, dMonthlySalary),
	m_dCommission(BASIC_COMMISSION)
{
}

ph4::CSalesman::~CSalesman()
{
}

double ph4::CSalesman::GetPayAmount() const
{
	return GetMonthlySalary() + m_dCommission;
}

string ph4::CSalesman::GetCompanyStandAsString() const
{
	static const string STR_SALESMAN = "Salesman";

	return STR_SALESMAN;
}


/* CManager class definition ****************************************************/
const double ph4::CManager::BASIC_BONUS = 800;

ph4::CManager::CManager(	const string& strFirstName,
							const string& strLastName,
							double dMonthlySalary /*= 0.0*/) :
	CEngineer(strFirstName, strLastName, dMonthlySalary),
	m_dBonus(BASIC_BONUS)
{
}

ph4::CManager::~CManager()
{
}

double ph4::CManager::GetPayAmount() const
{
	return GetMonthlySalary() + m_dBonus;
}

string ph4::CManager::GetCompanyStandAsString() const
{
	static const string STR_MANAGER = "Manager";

	return STR_MANAGER;
}