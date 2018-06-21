#pragma once

/*
Usuwamy pole kodu typu, usuwamy sta³e lub przesuwamy je w dó³ hierarchii.
Przesuwamy odpowiednie pola i metody w dó³ hierarchii.
Klasa CEmployee staje siê abstrakcyjna.
*/

namespace ph3
{
	class CEmployee
	{
	public:
		/**static const int ENGINEER = 0;**/
		/**static const int SALESMAN = 1;**/
		/**static const int MANAGER = 2;**/

		/**static const string STR_ENGINEER;**/
		/**static const string STR_SALESMAN;**/
		/**static const string STR_MANAGER;**/

		CEmployee(	const string& strFirstName,
					const string& strLastName,
					/**int iCompanyStand,**/
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

		/**virtual int GetCompanyStand() const
		{
			return m_iCompanyStand;
		}**/

		void SetMonthlySalary(double dMonthlySalary)
		{
			m_dMonthlySalary = dMonthlySalary;
		}

		double GetMonthlySalary() const
		{
			return m_dMonthlySalary;
		}

		/**void SetCommission(double dCommission);
		double GetCommission() const
		{
			return m_dCommission;
		}**/

		/**void SetBonus(double dBonus);
		double GetBonus() const
		{
			return m_dBonus;
		}**/

		/**double GetPayAmount() const;**/
		virtual double GetPayAmount() const = 0;

		friend ostream& operator <<(ostream& os, const CEmployee& oEmployee);

	/**private:**/
		/**string GetCompanyStandAsString() const;**/
	protected:
		virtual string GetCompanyStandAsString() const = 0;

	private:
		const string m_strFirstName;
		const string m_strLastName;
		/**int m_iCompanyStand;**/

		double m_dMonthlySalary; // Miesiêczna pensja podstawowa.
		/**double m_dCommission;**/ // Prowizja dla SALESMAN.
		/**double m_dBonus;**/ // Premia dla MANAGER
	};

	class CEngineer : public CEmployee
	{
	public:
		CEngineer(	const string& strFirstName,
					const string& strLastName,
					/**int iCompanyStand = CEmployee::ENGINEER,**/
					double dMonthlySalary = 0.0);
		virtual ~CEngineer();

		/**virtual int GetCompanyStand() const
		{
			return CEmployee::ENGINEER;
		}**/

		virtual double GetPayAmount() const;

	private:
		virtual string GetCompanyStandAsString() const;
	};

	class CSalesman : public CEmployee
	{
	public:
		CSalesman(	const string& strFirstName,
					const string& strLastName,
					/**int iCompanyStand = CEmployee::SALESMAN,**/
					double dMonthlySalary = 0.0);
		virtual ~CSalesman();

		/**virtual int GetCompanyStand() const
		{
			return CEmployee::SALESMAN;
		}**/

		void SetCommission(double dCommission)
		{
			m_dCommission = dCommission;
		}

		double GetCommission() const
		{
			return m_dCommission;
		}

		virtual double GetPayAmount() const;

	private:
		virtual string GetCompanyStandAsString() const;

		static const double BASIC_COMMISSION;
		double m_dCommission; // Prowizja.
	};

	class CManager : public CEngineer
	{
	public:
		CManager(	const string& strFirstName,
					const string& strLastName,
					/**int iCompanyStand = CEmployee::MANAGER,**/
					double dMonthlySalary = 0.0);
		virtual ~CManager();

		/**virtual int GetCompanyStand() const
		{
			return CEmployee::MANAGER;
		}**/

		void SetBonus(double dBonus)
		{
			m_dBonus = dBonus;
		}

		double GetBonus() const
		{
			return m_dBonus;
		}

		virtual double GetPayAmount() const;

	private:
		virtual string GetCompanyStandAsString() const;

		static const double BASIC_BONUS;
		double m_dBonus; // Premia.
	};
}