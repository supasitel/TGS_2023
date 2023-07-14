#include "target.h"

//コンストラクタ
ITarget::ITarget(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, "Target")
	, m_Width(0), m_Height(0), m_Radius(0.0f), m_Velocity(aqua::CVector2::ZERO)
{
}

//初期化
void ITarget::Initialize(void)
{
	m_Position = aqua::CVector2::ZERO;

	m_Velocity = aqua::CVector2::ZERO;
}

//更新
void ITarget::Update(void)
{
	using namespace aqua::mouse;

	aqua::CPoint mpos = GetCursorPos();

	m_Position += m_Velocity * aqua::GetDeltaTime();

	//if (m_Position.x > mpos.x && m_Position.x < mpos.x + m_Width ||
	//	m_Position.y > mpos.y && m_Position.x < mpos.y + m_Height)
	//{
	//	return;
	//}
	//else
	//{
	//	if (Trigger(BUTTON_ID::LEFT))
	//	{

	//	}
	//}

	CheckHitWall();

}

//描画
void ITarget::Draw(void)
{

}

//解放
void ITarget::Finalize(void)
{
}

//幅の取得
int ITarget::GetWidth(void)
{
	return m_Width;
}

//高さの取得
int ITarget::GetHeight(void)
{
	return m_Height;
}

//当たり半径の取得
float ITarget::GetRadius(void)
{
	return m_Radius;
}

//中心位置の取得
//aqua::CVector2 ITarget::GetCenterPosition(void)
//{
//	return aqua::CVector2();
//}

//壁判定
void ITarget::CheckHitWall(void)
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