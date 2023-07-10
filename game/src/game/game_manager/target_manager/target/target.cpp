#include "target.h"

//コンストラクタ
ITarget ::ITarget (aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Enemy")
	, m_Width(0), m_Height(0), m_Radius(0.0f), m_Velocity(aqua::CVector2::ZERO)
{
}

//初期化
void ITarget ::Initialize(void)
{
	//位置の初期化
	m_Position = aqua::CVector2::ZERO;

	//速度の初期化
	m_Velocity = aqua::CVector2::ZERO;
}

//更新
void ITarget ::Update(void)
{
	m_Position += m_Velocity * aqua::GetDeltaTime();

    //エネミーの位置
	m_Enemy.position = m_Position;

	CheckHitWall();
}

//描画
void ITarget ::Draw(void)
{
	m_Enemy.Draw();
}

//解放
void ITarget ::Finalize(void)
{
	m_Enemy.Delete();
}

//幅の取得
int ITarget ::GetWidth(void)
{
	return m_Width;
}

//高さの取得
int ITarget ::GetHeight(void)
{
	return m_Height;
}

//半径の取得
float ITarget ::GetRadius(void)
{
	return m_Radius;
}

//中心位置の取得
aqua::CVector2 ITarget ::GetCenterPosition(void)
{
	return m_Position+m_Enemy.anchor;
}

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
