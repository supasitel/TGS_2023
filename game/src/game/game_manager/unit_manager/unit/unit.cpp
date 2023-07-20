#include "unit.h"

const int IUnit::m_default_max_life = 1;
const float IUnit::m_dead_time = 0.5f;
const int IUnit::m_MaxLife = 1;

//�R���X�g���N�^
IUnit::IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category)
	:aqua::IGameObject(parent, name, category)
	, m_Position(aqua::CVector2::ZERO), m_Velocity(aqua::CVector2::ZERO), m_HitRadius(0.0f)
	,m_Life(m_default_max_life)
{
}

//�`��
void IUnit::Draw(void)
{
	m_UnitSprite.Draw();
}

//���
void IUnit::Finalize(void)
{
	m_UnitSprite.Delete();
}

bool IUnit::Damage(int damage)
{
	m_Life -= damage;

	return true;
}

//�ʒu�̎擾
aqua::CVector2 IUnit::GetPosition(void)
{
	return m_Position;
}

//���S�ʒu�̎擾
aqua::CVector2 IUnit::GetCenterPosition(void)
{
	//UnitSprite�̒��S�ʒu
	aqua::CVector2 t = aqua::CVector2((float)m_UnitSprite.GetTextureWidth() / 2.0f, (float)m_UnitSprite.GetTextureHeight() / 2.0f);

	//�ʒu��UnitSprite�̒��S�ʒu�𑫂��ĕԂ�
	return m_Position + t;
}

//�����蔼�a�̎擾
float IUnit::GetHitRadius(void)
{
	return m_HitRadius;
}

int IUnit::GetLife(void)
{
	return m_Life;
}

int IUnit::GetMaxLife(void)
{
	return m_MaxLife;
}

//�ǔ���
void IUnit::CheckHitWall(void)
{
}
