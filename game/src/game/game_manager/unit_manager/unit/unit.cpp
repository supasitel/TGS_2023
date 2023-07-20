#include "unit.h"

const int IUnit::m_default_max_life = 1;
const float IUnit::m_dead_time = 0.5f;
const int IUnit::m_MaxLife = 1;

//コンストラクタ
IUnit::IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category)
	:aqua::IGameObject(parent, name, category)
	, m_Position(aqua::CVector2::ZERO), m_Velocity(aqua::CVector2::ZERO), m_HitRadius(0.0f)
	,m_Life(m_default_max_life)
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

bool IUnit::Damage(int damage)
{
	m_Life -= damage;

	return true;
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
	aqua::CVector2 t = aqua::CVector2((float)m_UnitSprite.GetTextureWidth() / 2.0f, (float)m_UnitSprite.GetTextureHeight() / 2.0f);

	//位置とUnitSpriteの中心位置を足して返す
	return m_Position + t;
}

//当たり半径の取得
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

//壁判定
void IUnit::CheckHitWall(void)
{
}
