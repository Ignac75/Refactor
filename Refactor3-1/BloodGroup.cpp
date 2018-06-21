#include "stdafx.h"
#include "BloodGroup.h"

const CBloodGroup CBloodGroup::O(CBloodGroup::ECode::e0);
const CBloodGroup CBloodGroup::A(CBloodGroup::ECode::eA);
const CBloodGroup CBloodGroup::B(CBloodGroup::ECode::eB);
const CBloodGroup CBloodGroup::AB(CBloodGroup::ECode::eAB);

const string CBloodGroup::DESCR[] = {"0", "A", "B", "AB"};

CBloodGroup::CBloodGroup(CBloodGroup::ECode eCode):
	m_eCode(eCode)
{
	static_assert(sizeof(DESCR)/sizeof(DESCR[0]) == sizeof(ECode), "Update DESCR table.");
}