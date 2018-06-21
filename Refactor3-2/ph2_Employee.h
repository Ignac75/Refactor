#pragma once

/*
Przeprowadzamy samoenkapsulacjê pola z kodem typu - chcemy byæ gotowi na jego usuniêcie, a zatem
realizujemy do niego dostêp za pomoc¹ funkcji GetCompanyStand wszêdzie tam, gdzie wczeœniej by³o
wykorzystywane m_iCompanyStand.
Funkcja GetCompanyStand jest od razu wirtualizowana poniewa¿ zastepujemy kod typu podklasami
(wzorzec STRATEGIA)
*/

namespace ph2
{
	class CEmployee
	{
	public:
		static const int ENGINEER = 0;
		static const int SALESMAN = 1;
		static const int MANAGER = 2;

		static const string STR_ENGINEER;
		static const string STR_SALESMAN;
		static const string STR_MANAGER;

		CEmployee(	const string& strFirstName,
					const string& strLastName,
					int iCompanyStand,
					double dMonthlySalary = 0.0);
		virtual ~CEmployee();

		string GetFirstName() const
		{
			return m_strFirstName;
		}

		string GetLastName() const
		{
			return m_strLastName;
		}

		/**int GetCompanyStand() const**/
		virtual int GetCompanyStand() const
		{
			return m_iCompanyStand;
		}

		void SetMonthlySalary(double dMonthlySalary)
		{
			m_dMonthlySalary = dMonthlySalary;
		}

		double GetMonthlySalary() const
		{
			return m_dMonthlySalary;
		}

		void SetCommission(double dCommission);
		double GetCommission() const
		{
			return m_dCommission;
		}

		void SetBonus(double dBonus);
		double GetBonus() const
		{
			return m_dBonus;
		}

		double GetPayAmount() const;

		friend ostream& operator <<(ostream& os, const CEmployee& oEmployee);

	private:
		string GetCompanyStandAsString() const;

		const string m_strFirstName;
		const string m_strLastName;
		const int m_iCompanyStand;

		double m_dMonthlySalary; // Miesiêczna pensja podstawowa.
		double m_dCommission; // Prowizja dla SALESMAN.
		double m_dBonus; // Premia dla MANAGER
	};

	class CEngineer : public CEmployee
	{
	public:
		CEngineer(	const string& strFirstName,
					const string& strLastName,
					int iCompanyStand = CEmployee::ENGINEER,
					double dMonthlySalary = 0.0);
		virtual ~CEngineer();

		virtual int GetCompanyStand() const
		{
			return CEmployee::ENGINEER;
		}
	};

	class CSalesman : public CEmployee
	{
	public:
		CSalesman(	const string& strFirstName,
					const string& strLastName,
					int iCompanyStand = CEmployee::SALESMAN,
					double dMonthlySalary = 0.0);
		virtual ~CSalesman();

		virtual int GetCompanyStand() const
		{
			return CEmployee::SALESMAN;
		}
	};

	class CManager : public CEngineer
	{
	public:
		CManager(	const string& strFirstName,
					const string& strLastName,
					int iCompanyStand = CEmployee::MANAGER,
					double dMonthlySalary = 0.0);
		virtual ~CManager();

		virtual int GetCompanyStand() const
		{
			return CEmployee::MANAGER;
		}
	};
}
