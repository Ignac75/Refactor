#pragma once

/*
Je¿eli zachowanie zale¿y od typu, to rozwi¹zaniem jest zastosowanie polimorfizmu w celu obs³u¿enia
wariantów zachowania.
Sytuacjê z regu³y mo¿na rozpoznaæ po wystêpowaniu wyra¿eñ warunkowych. Mog¹ to byæ instrukcje switch lub
konstrukcje if...else, które sprawdzaj¹ typ i w zale¿noœci od niego kieruj¹ w ró¿ne miejsca w kodzie.
Samych instrukcji pozbywamy siê wykorzystuj¹c Zast¹pienie Instrukcji Warunkowej Polimorfizmem.
Jednak by to przekszta³cenie zadzia³a³o musimy zast¹piæ kody typów struktur¹ dziedziczenia, na której
póŸniej oprzemy polimorfizm.

Ka¿dy kod typu bêdzie reprezentowany przez inn¹ podklasê.
W tym przyk³adzie podklasy bêd¹ reprezentowa³y pracowników, którzy zajmuj¹ odpowiednie stanowiska w firmie.
Zastosujemy wzorzec STRATEGIA.
*/

namespace ph1
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
		string GetCompanyStandAsString() const;

		const string m_strFirstName;
		const string m_strLastName;
		const int m_iCompanyStand;

		double m_dMonthlySalary; // Miesiêczna pensja podstawowa.
		double m_dCommission; // Prowizja dla SALESMAN.
		double m_dBonus; // Premia dla MANAGER
	};
}
