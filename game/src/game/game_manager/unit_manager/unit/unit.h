#pragma once
#include "aqua.h"

class IUnit :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category);

	//�f�X�g���N�^
	~IUnit() = default;

	//�`��
	void Draw(void);

	//���
	void Finalize(void);

	//�ʒu�̎擾
	aqua::CVector2 GetPosition(void);

	//���S�ʒu�̎擾
	aqua::CVector2 GetCenterPosition(void);

	//�����蔼�a�̎擾
	float GetHitRadius(void);

	//�ǔ���
	void CheckHitWall(void);
protected:
	aqua::CSprite m_UnitSprite;
	aqua::CVector2 m_Position;
	aqua::CVector2 m_Velocity;

	float m_HitRadius;
};