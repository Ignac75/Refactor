#pragma once

/*
Chcê,aby nie da³o siê tworzyæ obiektów klasy CBloodGroup.
Przenoszê konstruktor do sekcji private.
Parametr typu liczbowego reprezentujê za pomoc¹ enum class.
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

		/**Nie potrzebujê tej funkcji poniewa¿ jej rolê zaczyna se³niaæ tablica DESCR
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