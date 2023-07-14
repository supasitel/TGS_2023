#include "unit.h"

//コンストラクタ
IUnit::IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category)
	:aqua::IGameObject(parent, name, category)
	, m_Position(aqua::CVector2::ZERO), m_Velocity(aqua::CVector2::ZERO), m_Accelerator(aqua::CVector2::ZERO)
	, m_HitRadius(0.0f), m_Width(0), m_Height(0)
{
}

void IUnit::Initialize(const std::string& file_name)
{
	m_UnitSprite.Create(file_name);

	m_HitRadius = (float)m_UnitSprite.GetTextureWidth() / 4.0f;

	m_State = STATE::MOVE;
}

void IUnit::Update(void)
{
	switch (m_State)
	{
	case STATE::MOVE:	Move(); break;
	}

    CheckHitWall();
}

void IUnit::Draw(void)
{
	m_UnitSprite.Draw();
}

void IUnit::Finalize(void)
{
	m_UnitSprite.Delete();
}

aqua::CVector2 IUnit::GetPosition(void)
{
	return m_Position;
}

aqua::CVector2 IUnit::GetCenterPosition(void)
{
	aqua::CVector2 k = aqua::CVector2((float)m_UnitSprite.GetTextureWidth() / 2.0f, (float)m_UnitSprite.GetTextureHeight() / 2.0f);
	return m_Position + k;
}

int IUnit::GetWidth(void)
{
	return m_Width;
}

int IUnit::GetHeight(void)
{
	return m_Height;
}

float IUnit::GetHitRadius(void)
{
	return m_HitRadius;
}

void IUnit::Move(void)
{
	m_Velocity += m_Accelerator;

	m_Position += m_Velocity * aqua::GetDeltaTime();

	m_Accelerator = aqua::CVector2::ZERO;

	m_UnitSprite.position = m_Position;
}

void IUnit::CheckHitWall(void)
{
    //幅の計算
    const int width = (float)(aqua::GetWindowWidth() - m_Width);

    //高さの計算
    const int height = (float)(aqua::GetWindowHeight() - m_Height);

    //上の壁判定
    if (m_Position.x < 0.0f)
    {
        m_Position.x = 0.0f - m_Position.x;

        m_Velocity.x *= -1.0f;
    }

    //下の壁判定
    if (m_Position.x > width)
    {
        m_Position.x = width - (m_Position.x - width);

        m_Velocity.x *= -1.0f;
    }

    //左の壁判定
    if (m_Position.y < 0.0f)
    {
        m_Position.y = 0.0f - m_Position.y;

        m_Velocity.y *= -1.0f;
    }

    //右の壁判定
    if (m_Position.y > height)
    {
        m_Position.y = height - (m_Position.y - height);

        m_Velocity.y *= -1.0f;
    }

}
