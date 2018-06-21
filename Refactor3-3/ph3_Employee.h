#pragma once

/*
W klasie pracownika usuwamy m_iCompanyStand.
Pod³¹czamy dynamicznie tworzony obiekt stanowiska w firmie.
Z tego powodu deklaracja CCompanyStand musi poprzedzaæ deklaracjê CEmployee.
Jednoczeœnie sta³e typu przenosimy do CCompanyStand.
Upubliczniam metodê SetCompanyStand aby móc testowaæ dynamiczn¹ zmianê stanowiska
pracownika.
*/

namespace ph3
{
	class CCompanyStand
	{
	public:
		static const int ENGINEER = 0;
		static const int SALESMAN = 1;
		static const int MANAGER = 2;

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
			return ENGINEER;
		}
	};


	class CSalesman : public CCompanyStand
	{
	public:
		CSalesman();
		virtual ~CSalesman();

		virtual int GetCompanyStand() const
		{
			return SALESMAN;
		}
	};


	class CManager : public CEngineer
	{
	public:
		CManager();
		virtual ~CManager();

		virtual int GetCompanyStand() const
		{
			return MANAGER;
		}
	};

	class CEmployee
	{
	public:
		/**static const int ENGINEER = 0;
		static const int SALESMAN = 1;
		static const int MANAGER = 2;**/

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

		void SetCompanyStand(int iCompanyStand);

		int GetCompanyStand() const
		{
			/**return m_iCompanyStand;**/
			return m_upCompanyStand->GetCompanyStand();
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
		/**void SetCompanyStand(int iCompanyStand);**/
		string GetCompanyStandAsString() const;

		const string m_strFirstName;
		const string m_strLastName;
		/**int m_iCompanyStand;**/
		unique_ptr<CCompanyStand> m_upCompanyStand;

		double m_dMonthlySalary; // Miesiêczna pensja podstawowa.
		double m_dCommission; // Prowizja dla SALESMAN.
		double m_dBonus; // Premia dla MANAGER
	};	
}