#include "stdafx.h"
#include "ph5_Employee.h"


/* CCompanyStand class definition ****************************************************/
unique_ptr<ph5::CCompanyStand> ph5::CCompanyStand::Create(EStand eStand, double dMonthlySalary /*= 0.0*/)
{
	switch (eStand)
	{
		case EStand::eEngineer:
			return make_unique<CEngineer>();

		case EStand::eSalesman:
			return make_unique<CSalesman>();

		case EStand::eManager:
			return make_unique<CManager>();

		default:
			_ASSERT(false);
			return nullptr;
	}
}

ph5::CCompanyStand::CCompanyStand(double dMonthlySalary /*= 0.0*/) :
	m_dMonthlySalary(dMonthlySalary)
{
}

ph5::CCompanyStand::~CCompanyStand()
{
}

void ph5::CCompanyStand::SetCommission(double dCommission)
{
}

double ph5::CCompanyStand::GetCommission() const
{
	return 0.0;
}

void ph5::CCompanyStand::SetBonus(double dBonus)
{
}

double ph5::CCompanyStand::GetBonus() const
{
	return 0.0;
}


/* CEngineer class definition ****************************************************/
ph5::CEngineer::CEngineer(double dMonthlySalary /*= 0.0*/) :
	CCompanyStand(dMonthlySalary)
{
}

ph5::CEngineer::~CEngineer()
{
}

string ph5::CEngineer::GetCompanyStandAsString() const
{
	static const string STR_ENGINEER = "Engineer";

	return STR_ENGINEER;
}

double ph5::CEngineer::GetPayAmount() const
{
	return m_dMonthlySalary;
}


/* CSalesman class definition ****************************************************/
const double ph5::CSalesman::BASIC_COMMISSION = 500;

ph5::CSalesman::CSalesman(double dMonthlySalary /*= 0.0*/) :
	CCompanyStand(dMonthlySalary),
	m_dCommission(BASIC_COMMISSION)
{
}

ph5::CSalesman::~CSalesman()
{
}

string ph5::CSalesman::GetCompanyStandAsString() const
{
	static const string STR_SALESMAN = "Salesman";

	return STR_SALESMAN;
}

void ph5::CSalesman::SetCommission(double dCommission)
{
	m_dCommission = dCommission;
}

double ph5::CSalesman::GetCommission() const
{
	return m_dCommission;
}

double ph5::CSalesman::GetPayAmount() const
{
	return m_dMonthlySalary + m_dCommission;
}


/* CManager class definition ****************************************************/
const double ph5::CManager::BASIC_BONUS = 800;

ph5::CManager::CManager(double dMonthlySalary /*= 0.0*/) :
	CEngineer(dMonthlySalary),
	m_dBonus(BASIC_BONUS)
{
}

ph5::CManager::~CManager()
{
}

string ph5::CManager::GetCompanyStandAsString() const
{
	static const string STR_MANAGER = "Manager";

	return STR_MANAGER;
}

void ph5::CManager::SetBonus(double dBonus)
{
	m_dBonus = dBonus;
}

double ph5::CManager::GetBonus() const
{
	return m_dBonus;
}

double ph5::CManager::GetPayAmount() const
{
	return m_dMonthlySalary + m_dBonus;
}


/* CEmployee class definition ****************************************************/
ph5::CEmployee::CEmployee(	const string& strFirstName,
							const string& strLastName,
							CCompanyStand::EStand eStand,
							double dMonthlySalary /*= 0.0*/) :
	m_strFirstName(strFirstName),
	m_strLastName(strLastName)
{
	SetCompanyStand(eStand, dMonthlySalary);
}

ph5::CEmployee::~CEmployee()
{
}

void ph5::CEmployee::SetCompanyStand(CCompanyStand::EStand eStand, double dMonthlySalary /*= 0.0*/)
{
	m_upCompanyStand = CCompanyStand::Create(eStand, dMonthlySalary);
}

ph5::CCompanyStand::EStand ph5::CEmployee::GetCompanyStand() const
{
	return m_upCompanyStand->GetCompanyStand();
}

void ph5::CEmployee::SetMonthlySalary(double dMonthlySalary)
{
	m_upCompanyStand->SetMonthlySalary(dMonthlySalary);
}

double ph5::CEmployee::GetMonthlySalary() const
{
	return m_upCompanyStand->GetMonthlySalary();
}

void ph5::CEmployee::SetCommission(double dCommission)
{
	m_upCompanyStand->SetCommission(dCommission);
}

double ph5::CEmployee::GetCommission() const
{
	return m_upCompanyStand->GetCommission();
}

void ph5::CEmployee::SetBonus(double dBonus)
{
	m_upCompanyStand->SetBonus(dBonus);
}

double ph5::CEmployee::GetBonus() const
{
	return m_upCompanyStand->GetBonus();
}

double ph5::CEmployee::GetPayAmount() const
{
	return m_upCompanyStand->GetPayAmount();
}

ostream& ph5::operator <<(ostream& os, const ph5::CEmployee& oEmployee)
{
	os << "First name: " << oEmployee.GetFirstName() << endl;
	os << "Last name: " << oEmployee.GetLastName() << endl;
	os << "Company stand: " << oEmployee.GetCompanyStandAsString() << endl;
	os << "Salary: " << put_money(oEmployee.GetPayAmount(), true) << endl;

	return os;
}

string ph5::CEmployee::GetCompanyStandAsString() const
{
	return m_upCompanyStand->GetCompanyStandAsString();
}