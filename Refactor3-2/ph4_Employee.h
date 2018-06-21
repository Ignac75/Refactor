#pragma once

/*
Postaæ finalna po usuniêciu komentarzy.
*/

namespace ph4
{
	class CEmployee
	{
	public:
		CEmployee(	const string& strFirstName,
					const string& strLastName,
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

		void SetMonthlySalary(double dMonthlySalary)
		{
			m_dMonthlySalary = dMonthlySalary;
		}

		double GetMonthlySalary() const
		{
			return m_dMonthlySalary;
		}

		virtual double GetPayAmount() const = 0;

		friend ostream& operator <<(ostream& os, const CEmployee& oEmployee);

	protected:
		virtual string GetCompanyStandAsString() const = 0;

	private:
		const string m_strFirstName;
		const string m_strLastName;
		double m_dMonthlySalary; // Miesiêczna pensja podstawowa.
	};

	class CEngineer : public CEmployee
	{
	public:
		CEngineer(	const string& strFirstName,
					const string& strLastName,
					double dMonthlySalary = 0.0);
		virtual ~CEngineer();

		virtual double GetPayAmount() const;

	private:
		virtual string GetCompanyStandAsString() const;
	};

	class CSalesman : public CEmployee
	{
	public:
		CSalesman(	const string& strFirstName,
					const string& strLastName,
					double dMonthlySalary = 0.0);
		virtual ~CSalesman();

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
					double dMonthlySalary = 0.0);
		virtual ~CManager();

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
