#pragma once

/*
Przeprowadzamy samoenkapsulacj� pola z kodem typu - chcemy by� gotowi na jego usuni�cie, a zatem
realizujemy do niego dost�p za pomoc� funkcji GetCompanyStand wsz�dzie tam, gdzie wcze�niej by�o
wykorzystywane m_iCompanyStand.
Wprowadzamy tak�e funkcj� SetCompanyStand aby ustawi� ten member w konstruktorze.
Wprowadzamy abstrakcyjn� klas� reprezentuj�c� kod typu, poszczeg�lne kody reprezentuj�
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

		double m_dMonthlySalary; // Miesi�czna pensja podstawowa.
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