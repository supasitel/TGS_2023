#include "unit.h"

//コンストラクタ
IUnit::IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category)
	:aqua::IGameObject(parent, name, category)
	, m_Position(aqua::CVector2::ZERO), m_Velocity(aqua::CVector2::ZERO), m_HitRadius(0.0f)
{
}

//描画
void IUnit::Draw(void)
{
	m_UnitSprite.Draw();
}

//解放
void IUnit::Finalize(void)
{
	m_UnitSprite.Delete();
}

//位置の取得
aqua::CVector2 IUnit::GetPosition(void)
{
	return m_Position;
}

//中心位置の取得
aqua::CVector2 IUnit::GetCenterPosition(void)
{
	//UnitSpriteの中心位置
	aqua::CVector2 p = aqua::CVector2((float)m_UnitSprite.GetTextureWidth() / 2.0f, (float)m_UnitSprite.GetTextureHeight() / 2.0f);

	//位置とUnitSpriteの中心位置を足して返す
	return m_Position + p;
}

//当たり半径の取得
float IUnit::GetHitRadius(void)
{
	return m_HitRadius;
}

//壁判定
void IUnit::CheckHitWall(void)
{
}
