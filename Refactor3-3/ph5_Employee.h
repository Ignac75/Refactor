#pragma once

/*
Przenosimy dane p³acowe do struktury klas CCompanyStand.
Poni¿ej postaæ koñcowa tego przekszta³cenia. 
*/

namespace ph5
{
	class CCompanyStand
	{
	public:
		enum class EStand
		{
			eEngineer = 0,
			eSalesman,
			eManager
		};

		static unique_ptr<CCompanyStand> Create(EStand eStand, double dMonthlySalary = 0.0);

		CCompanyStand(double dMonthlySalary = 0.0);
		virtual ~CCompanyStand();

		virtual EStand GetCompanyStand() const = 0;
		virtual string GetCompanyStandAsString() const = 0;

		void SetMonthlySalary(double dMonthlySalary)
		{
			m_dMonthlySalary = dMonthlySalary;
		}

		double GetMonthlySalary() const
		{
			return m_dMonthlySalary;
		}

		virtual void SetCommission(double /*dCommission*/);
		virtual double GetCommission() const;
		virtual void SetBonus(double /*dBonus*/);
		virtual double GetBonus() const;
		virtual double GetPayAmount() const = 0;

	protected:
		double m_dMonthlySalary; // Miesiêczna pensja podstawowa
	};


	class CEngineer : public CCompanyStand
	{
	public:
		CEngineer(double dMonthlySalary = 0.0);
		virtual ~CEngineer();

		virtual EStand GetCompanyStand() const
		{
			return EStand::eEngineer;
		}

		virtual string GetCompanyStandAsString() const;
		virtual double GetPayAmount() const;
	};


	class CSalesman : public CCompanyStand
	{
	public:
		static const double BASIC_COMMISSION;
		
		CSalesman(double dMonthlySalary = 0.0);
		virtual ~CSalesman();

		virtual EStand GetCompanyStand() const
		{
			return EStand::eSalesman;
		}

		virtual string GetCompanyStandAsString() const;
		virtual void SetCommission(double /*dCommission*/);
		virtual double GetCommission() const;
		virtual double GetPayAmount() const;

	protected:
		double m_dCommission; // Prowizja
	};


	class CManager : public CEngineer
	{
	public:
		static const double BASIC_BONUS;

		CManager(double dMonthlySalary = 0.0);
		virtual ~CManager();

		virtual EStand GetCompanyStand() const
		{
			return EStand::eManager;
		}

		virtual string GetCompanyStandAsString() const;
		virtual void SetBonus(double /*dBonus*/);
		virtual double GetBonus() const;
		virtual double GetPayAmount() const;

	protected:
		double m_dBonus; // Premia
	};

	class CEmployee
	{
	public:
		CEmployee(	const string& strFirstName,
					const string& strLastName,
					CCompanyStand::EStand eStand,
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

		void SetCompanyStand(CCompanyStand::EStand eStand, double dMonthlySalary = 0.0);
		CCompanyStand::EStand GetCompanyStand() const;
		void SetMonthlySalary(double dMonthlySalary);
		double GetMonthlySalary() const;
		void SetCommission(double dCommission);
		double GetCommission() const;
		void SetBonus(double dBonus);
		double GetBonus() const;
		double GetPayAmount() const;
		friend ostream& operator <<(ostream& os, const CEmployee& oEmployee);

	private:
		string GetCompanyStandAsString() const;

		const string m_strFirstName;
		const string m_strLastName;
		unique_ptr<CCompanyStand> m_upCompanyStand;
	};	
}