#pragma once
#include "../../unit/unit.h"

class ITarget :public IUnit
{
public:
	//�R���X�g���N�^
	ITarget(aqua::IGameObject* parent, const std::string& name);

	//�f�X�g���N�^
	~ITarget() = default;

	//������
	void Initialize(const std::string& file_name);
private:
	static const float m_max_velocity;
	static const float m_min_velocity;
	aqua::CVector2	   m_Velocity;

};