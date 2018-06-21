#pragma once

/*
Porz¹dkujemy kod:
1. Sta³e stanowisk w firmie reprezentujemy za pomoc¹ enum class.
2. Sta³e STR_ i GetCompanyStandAsString przenosimy z CEmployee do funkcji
wirtualnej  CCompanyStand.
3. Zawartoœæ wytwórcz¹ CEmployee::SetCompanyStand przenoszê do CCompanyStand::Create.
*/

namespace ph4
{
	class CCompanyStand
	{
	public:
		/**static const int ENGINEER = 0;
		static const int SALESMAN = 1;
		static const int MANAGER = 2;**/
		enum class EStand
		{
			eEngineer = 0,
			eSalesman,
			eManager
		};

		static unique_ptr<CCompanyStand> Create(EStand eStand);

		CCompanyStand();
		virtual ~CCompanyStand();

		virtual /**int**/EStand GetCompanyStand() const = 0;
		virtual string GetCompanyStandAsString() const = 0;
	};


	class CEngineer : public CCompanyStand
	{
	public:
		CEngineer();
		virtual ~CEngineer();

		virtual /**int**/EStand GetCompanyStand() const
		{
			/**return ENGINEER;**/
			return EStand::eEngineer;
		}

		virtual string GetCompanyStandAsString() const;
	};


	class CSalesman : public CCompanyStand
	{
	public:
		CSalesman();
		virtual ~CSalesman();

		virtual /**int**/EStand GetCompanyStand() const
		{
			/**return SALESMAN;**/
			return EStand::eSalesman;
		}

		virtual string GetCompanyStandAsString() const;
	};


	class CManager : public CEngineer
	{
	public:
		CManager();
		virtual ~CManager();

		virtual /**int**/EStand GetCompanyStand() const
		{
			/**return MANAGER;**/
			return EStand::eManager;
		}

		virtual string GetCompanyStandAsString() const;
	};

	class CEmployee
	{
	public:
		/**static const string STR_ENGINEER;
		static const string STR_SALESMAN;
		static const string STR_MANAGER;**/

		CEmployee(	const string& strFirstName,
					const string& strLastName,
					/**int iCompanyStand,**/
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

		void SetCompanyStand(/**int iCompanyStand**/CCompanyStand::EStand eStand);

		/**int**/CCompanyStand::EStand GetCompanyStand() const
		{
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
		string GetCompanyStandAsString() const;

		const string m_strFirstName;
		const string m_strLastName;
		unique_ptr<CCompanyStand> m_upCompanyStand;

		double m_dMonthlySalary; // Miesiêczna pensja podstawowa.
		double m_dCommission; // Prowizja dla SALESMAN.
		double m_dBonus; // Premia dla MANAGER
	};	
}