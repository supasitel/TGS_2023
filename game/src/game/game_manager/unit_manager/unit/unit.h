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

	virtual bool Damage(int damage);

	//�ʒu�̎擾
	aqua::CVector2 GetPosition(void);

	//���S�ʒu�̎擾
	aqua::CVector2 GetCenterPosition(void);

	//�����蔼�a�̎擾
	float GetHitRadius(void);

	int GetLife(void);

	int GetMaxLife(void);

	//�ǔ���
	void CheckHitWall(void);
protected:
	//���ID
	enum class STATE
	{
		LIVE,
		DEAD,
	};

	static const int m_default_max_life;
	static const float m_dead_time;
	static const int m_MaxLife;
	aqua::CSprite m_UnitSprite;
	aqua::CVector2 m_Position;
	aqua::CVector2 m_Velocity;
	aqua::CTimer	m_DeadTimer;
	float m_HitRadius;
	int m_Life;
	
	STATE	m_State;
	
};