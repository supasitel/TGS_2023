#include "unit.h"

//コンストラクタ
IUnit::IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category)
	:aqua::IGameObject(parent, name, category)
	, m_Position(aqua::CVector2::ZERO), m_Velocity(aqua::CVector2::ZERO), m_HitRadius(0.0f)
{
}

//位置の取得
aqua::CVector2 IUnit::GetPosition(void)
{
	//取得した位置を返す
	return m_Position;
}

//当たり半径の取得
float IUnit::GetHitRadius(void)
{
	//取得した当たり半径を返す
	return m_HitRadius;
}