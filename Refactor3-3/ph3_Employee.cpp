#include "stdafx.h"
#include "ph3_Employee.h"


/* CCompanyStand class definition ****************************************************/
ph3::CCompanyStand::CCompanyStand()
{
}

ph3::CCompanyStand::~CCompanyStand()
{
}


/* CEngineer class definition ****************************************************/
ph3::CEngineer::CEngineer() :
	CCompanyStand()
{
}

ph3::CEngineer::~CEngineer()
{
}


/* CSalesman class definition ****************************************************/
ph3::CSalesman::CSalesman() :
	CCompanyStand()
{
}

ph3::CSalesman::~CSalesman()
{
}


/* CManager class definition ****************************************************/
ph3::CManager::CManager() :
	CEngineer()
{
}

ph3::CManager::~CManager()
{
}


/* CEmployee class definition ****************************************************/
const string ph3::CEmployee::STR_ENGINEER = "Engineer";
const string ph3::CEmployee::STR_SALESMAN = "Salesman";
const string ph3::CEmployee::STR_MANAGER = "Manager";

static const double BASIC_COMMISSION_FOR_SALESMAN = 500;
static const double BASIC_BONUS_FOR_MANAGER = 800;

ph3::CEmployee::CEmployee(	const string& strFirstName,
							const string& strLastName,
							int iCompanyStand,
							double dMonthlySalary /*= 0.0*/) :
	m_strFirstName(strFirstName),
	m_strLastName(strLastName),
	m_dMonthlySalary(dMonthlySalary),
	m_dCommission(0.0),
	m_dBonus(0.0)
{
	SetCompanyStand(iCompanyStand);
	if (GetCompanyStand() == CCompanyStand::SALESMAN)
	{
		m_dCommission = BASIC_COMMISSION_FOR_SALESMAN;
	}
	else if (GetCompanyStand() == CCompanyStand::MANAGER)
	{
		m_dBonus = BASIC_BONUS_FOR_MANAGER;
	}
}

ph3::CEmployee::~CEmployee()
{
}

void ph3::CEmployee::SetCompanyStand(int iCompanyStand)
{
	switch (iCompanyStand)
	{
		case CCompanyStand::ENGINEER:
			m_upCompanyStand = make_unique<CEngineer>();
			break;

		case CCompanyStand::SALESMAN:
			m_upCompanyStand = make_unique<CSalesman>();
			break;

		case CCompanyStand::MANAGER:
			m_upCompanyStand = make_unique<CManager>();
			break;

		default:
			_ASSERT(false);
			break;
	}
}

void ph3::CEmployee::SetCommission(double dCommission)
{
	_ASSERT(GetCompanyStand() == CCompanyStand::SALESMAN);
	if (GetCompanyStand() == CCompanyStand::SALESMAN)
	{
		m_dCommission = dCommission;
	}
}

void ph3::CEmployee::SetBonus(double dBonus)
{
	_ASSERT(GetCompanyStand() == CCompanyStand::MANAGER);
	if (GetCompanyStand() == CCompanyStand::MANAGER)
	{
		m_dBonus = dBonus;
	}
}

double ph3::CEmployee::GetPayAmount() const
{
	switch (GetCompanyStand())
	{
		case CCompanyStand::ENGINEER:
			return m_dMonthlySalary;

		case CCompanyStand::SALESMAN:
			return m_dMonthlySalary + m_dCommission;

		case CCompanyStand::MANAGER:
			return m_dMonthlySalary + m_dBonus;

		default:
			_ASSERT(false);
			break;
	}

	return 0.0;
}

ostream& ph3::operator <<(ostream& os, const ph3::CEmployee& oEmployee)
{
	os << "First name: " << oEmployee.GetFirstName() << endl;
	os << "Last name: " << oEmployee.GetLastName() << endl;
	os << "Company stand: " << oEmployee.GetCompanyStandAsString() << endl;
	os << "Salary: " << put_money(oEmployee.GetPayAmount(), true) << endl;

	return os;
}

string ph3::CEmployee::GetCompanyStandAsString() const
{
	switch (GetCompanyStand())
	{
		case CCompanyStand::ENGINEER:
			return STR_ENGINEER;

		case CCompanyStand::SALESMAN:
			return STR_SALESMAN;

		case CCompanyStand::MANAGER:
			return STR_MANAGER;

		default:
			_ASSERT(false);
			break;
	}

	return "";
}