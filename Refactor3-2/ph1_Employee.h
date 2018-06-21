#pragma once

/*
Je�eli zachowanie zale�y od typu, to rozwi�zaniem jest zastosowanie polimorfizmu w celu obs�u�enia
wariant�w zachowania.
Sytuacj� z regu�y mo�na rozpozna� po wyst�powaniu wyra�e� warunkowych. Mog� to by� instrukcje switch lub
konstrukcje if...else, kt�re sprawdzaj� typ i w zale�no�ci od niego kieruj� w r�ne miejsca w kodzie.
Samych instrukcji pozbywamy si� wykorzystuj�c Zast�pienie Instrukcji Warunkowej Polimorfizmem.
Jednak by to przekszta�cenie zadzia�a�o musimy zast�pi� kody typ�w struktur� dziedziczenia, na kt�rej
p�niej oprzemy polimorfizm.

Ka�dy kod typu b�dzie reprezentowany przez inn� podklas�.
W tym przyk�adzie podklasy b�d� reprezentowa�y pracownik�w, kt�rzy zajmuj� odpowiednie stanowiska w firmie.
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

		double m_dMonthlySalary; // Miesi�czna pensja podstawowa.
		double m_dCommission; // Prowizja dla SALESMAN.
		double m_dBonus; // Premia dla MANAGER
	};
}
