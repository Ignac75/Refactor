#pragma once

/*
Chc�,aby nie da�o si� tworzy� obiekt�w klasy CBloodGroup.
Przenosz� konstruktor do sekcji private.
Parametr typu liczbowego reprezentuj� za pomoc� enum class.
*/

namespace ph3
{
	class CBloodGroup
	{
	public:
		static const CBloodGroup O;
		static const CBloodGroup A;
		static const CBloodGroup B;
		static const CBloodGroup AB;

		/**CBloodGroup(int iGroup);**/
		CBloodGroup(const CBloodGroup& oBloodGroup) = default;
		~CBloodGroup() = default;

		/**int GetGroup() const
		{
			return m_iGroup;
		}**/

		/**Nie potrzebuj� tej funkcji poniewa� jej rol� zaczyna se�nia� tablica DESCR
		static const CBloodGroup& GetBloodGroup(int iGroup);**/
		string AsString() const
		{
			return DESCR[static_cast<int>(m_eGroup)];
		}

	private:
		enum class EGroup
		{
			e0 = 0,
			eA,
			eB,
			eAB
		};
		
		static const string DESCR[];

		CBloodGroup(EGroup eGroup);

		/**int m_iGroup**/;
		EGroup m_eGroup;
	};
}