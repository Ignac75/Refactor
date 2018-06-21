#include "stdafx.h"
#include "ph1_Employee.h"

const string ph1::CEmployee::STR_ENGINEER = "Engineer";
const string ph1::CEmployee::STR_SALESMAN = "Salesman";
const string ph1::CEmployee::STR_MANAGER = "Manager";

static const double BASIC_COMMISSION_FOR_SALESMAN = 500;
static const double BASIC_BONUS_FOR_MANAGER = 800;

ph1::CEmployee::CEmployee(	const string& strFirstName,
							const string& strLastName,
							int iCompanyStand,
							double dMonthlySalary /*= 0.0*/) :
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	m_iCompanyStand(iCompanyStand),
	m_dMonthlySalary(dMonthlySalary),
	m_dCommission(0.0),
	m_dBonus(0.0)
{
	if (m_iCompanyStand == SALESMAN)
	{
		m_dCommission = BASIC_COMMISSION_FOR_SALESMAN;
	}
	else if (m_iCompanyStand == MANAGER)
	{
		m_dBonus = BASIC_BONUS_FOR_MANAGER;
	}
}

ph1::CEmployee::~CEmployee()
{
}

void ph1::CEmployee::SetCommission(double dCommission)
{
	_ASSERT(m_iCompanyStand == SALESMAN);
	if (m_iCompanyStand == SALESMAN)
	{
		m_dCommission = dCommission;
	}
}

void ph1::CEmployee::SetBonus(double dBonus)
{
	_ASSERT(m_iCompanyStand == MANAGER);
	if (m_iCompanyStand == MANAGER)
	{
		m_dBonus = dBonus;
	}
}

double ph1::CEmployee::GetPayAmount() const
{
	switch (m_iCompanyStand)
	{
		case ENGINEER:
			return m_dMonthlySalary;

		case SALESMAN:
			return m_dMonthlySalary + m_dCommission;

		case MANAGER:
			return m_dMonthlySalary + m_dBonus;

		default:
			_ASSERT(false);
			break;
	}

	return 0.0;
}

ostream& ph1::operator <<(ostream& os, const ph1::CEmployee& oEmployee)
{
	os << "First name: " << oEmployee.GetFirstName() << endl;
	os << "Last name: " << oEmployee.GetLastName() << endl;
	os << "Company stand: " << oEmployee.GetCompanyStandAsString() << endl;
	os << "Salary: " << put_money(oEmployee.GetPayAmount(), true) << endl;

	return os;
}

string ph1::CEmployee::GetCompanyStandAsString() const
{
	switch (m_iCompanyStand)
	{
		case ENGINEER:
			return STR_ENGINEER;

		case SALESMAN:
			return STR_SALESMAN;

		case MANAGER:
			return STR_MANAGER;

		default:
			_ASSERT(false);
			break;
	}

	return "";
}
