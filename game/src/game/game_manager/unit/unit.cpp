#include "unit.h"

//�R���X�g���N�^
IUnit::IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category)
	:aqua::IGameObject(parent, name, category)
	, m_Position(aqua::CVector2::ZERO), m_Velocity(aqua::CVector2::ZERO), m_HitRadius(0.0f)
{
}

//�ʒu�̎擾
aqua::CVector2 IUnit::GetPosition(void)
{
	//�擾�����ʒu��Ԃ�
	return m_Position;
}

//�����蔼�a�̎擾
float IUnit::GetHitRadius(void)
{
	//�擾���������蔼�a��Ԃ�
	return m_HitRadius;
}