#pragma once
#include "aqua.h"

class IUnit :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category);

	//�f�X�g���N�^
	~IUnit() = default;

	//�ʒu�̎擾
	aqua::CVector2 GetPosition(void);

	//�����蔼�a�̎擾
	float GetHitRadius(void);
protected:
	aqua::CVector2 m_Position;	//�ʒu
	aqua::CVector2 m_Velocity;	//���x
	float m_HitRadius;			//�����蔼�a
};