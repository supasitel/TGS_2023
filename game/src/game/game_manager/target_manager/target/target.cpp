#include "target.h"

const float ITarget::m_max_velocity = 2000.0f;
const float ITarget::m_min_velocity = 1000.0f;

//コンストラクタ
ITarget::ITarget(aqua::IGameObject* parent, const std::string& name)
	:IUnit(parent,name,"TargetUnit")
{
}

//初期化
void ITarget::Initialize(const std::string& file_name)
{
	IUnit::Initialize(file_name);

	float speed = (float)aqua::Rand(m_max_velocity,m_min_velocity);

	m_Velocity.x = speed;
	m_Velocity.y = speed;
}
