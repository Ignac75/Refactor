#include "stdafx.h"
#include "ph3_BloodGroup.h"

/**const ph2::CBloodGroup ph2::CBloodGroup::O(0);**/
const ph3::CBloodGroup ph3::CBloodGroup::O(CBloodGroup::EGroup::e0);
/**const ph2::CBloodGroup ph2::CBloodGroup::A(1);**/
const ph3::CBloodGroup ph3::CBloodGroup::A(CBloodGroup::EGroup::eA);
/**const ph2::CBloodGroup ph2::CBloodGroup::B(2);**/
const ph3::CBloodGroup ph3::CBloodGroup::B(CBloodGroup::EGroup::eB);
/**const ph2::CBloodGroup ph2::CBloodGroup::AB(3);**/
const ph3::CBloodGroup ph3::CBloodGroup::AB(CBloodGroup::EGroup::eAB);

const string ph3::CBloodGroup::DESCR[] = {"0", "A", "B", "AB"};

/**ph2::CBloodGroup::CBloodGroup(int iGroup):
	m_iGroup(iGroup)**/
ph3::CBloodGroup::CBloodGroup(CBloodGroup::EGroup eGroup) :
	m_eGroup(eGroup)
{
	static_assert(sizeof(DESCR)/sizeof(DESCR[0]) == sizeof(EGroup), "Update DESCR table.");
}

/**const ph2::CBloodGroup& ph2::CBloodGroup::GetBloodGroup(int iGroup)
{
	switch (iGroup)
	{
		case 0:
			return O;

		case 1:
			return A;

		case 2:
			return B;

		case 3:
			return AB;

		default:
			_ASSERT(false);
			return O;
	}
}**/
 