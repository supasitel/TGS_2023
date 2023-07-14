#pragma once
#include "../../unit/unit.h"

class ITarget :public IUnit
{
public:
	//コンストラクタ
	ITarget(aqua::IGameObject* parent, const std::string& name);

	//デストラクタ
	~ITarget() = default;

	//初期化
	void Initialize(const std::string& file_name);
private:
	static const float m_max_velocity;
	static const float m_min_velocity;
	aqua::CVector2	   m_Velocity;

};