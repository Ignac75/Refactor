#pragma once

/*
Przeprowadzamy samoenkapsulacjê pola z kodem typu - chcemy byæ gotowi na jego usuniêcie, a zatem
realizujemy do niego dostêp za pomoc¹ funkcji GetCompanyStand wszêdzie tam, gdzie wczeœniej by³o
wykorzystywane m_iCompanyStand.
Wprowadzamy tak¿e funkcjê SetCompanyStand aby ustawiæ ten member w konstruktorze.
Wprowadzamy abstrakcyjn¹ klasê reprezentuj¹c¹ kod typu, poszczególne kody reprezentuj¹
podklasy (wzorzec STAN)
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

		int GetCompanyStand() const
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
		void SetCompanyStand(int iCompanyStand)
		{
			m_iCompanyStand = iCompanyStand;
		}

		string GetCompanyStandAsString() const;

		const string m_strFirstName;
		const string m_strLastName;
		/**const int m_iCompanyStand;**/
		int m_iCompanyStand;

		double m_dMonthlySalary; // Miesiêczna pensja podstawowa.
		double m_dCommission; // Prowizja dla SALESMAN.
		double m_dBonus; // Premia dla MANAGER
	};

	
	class CCompanyStand
	{
	public:
		CCompanyStand();
		virtual ~CCompanyStand();

		virtual int GetCompanyStand() const = 0;
	};
	
	
	class CEngineer : public CCompanyStand
	{
	public:
		CEngineer();
		virtual ~CEngineer();

		virtual int GetCompanyStand() const
		{
			return CEmployee::ENGINEER;
		}
	};


	class CSalesman : public CCompanyStand
	{
	public:
		CSalesman();
		virtual ~CSalesman();

		virtual int GetCompanyStand() const
		{
			return CEmployee::SALESMAN;
		}
	};


	class CManager : public CEngineer
	{
	public:
		CManager();
		virtual ~CManager();

		virtual int GetCompanyStand() const
		{
			return CEmployee::MANAGER;
		}
	};
}