#include "wrong_target.h"
#include "../../../ui_manager/time/time.h"

const std::string CWrongTarget::m_name = "Wrong";	//名前
const std::string CWrongTarget::m_category = "WrongTarget";	//カテゴリー
const float CWrongTarget::m_one_timer = 1.0f;			//1秒
const float CWrongTarget::m_max_speed = 100.0f;			//最高速度
const float CWrongTarget::m_min_speed = 20.0f;			//最低速度

//コンストラクタ
CWrongTarget::CWrongTarget(aqua::IGameObject* parent)
	:IUnit(parent, m_name, m_category)
	, m_Width(100.0f), m_Height(138.0f), m_WrongTarget_Count(10)
{
}

//初期化
void CWrongTarget::Initialize(void)
{
	//不正解ターゲットの生成
	m_WrongTarget.Create("data\\wrong.png");

	//位置の代入
	m_Position = m_WrongTarget.position;

	//ランダムな位置に生成
	m_Position.x = aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = aqua::Rand(aqua::GetWindowHeight() - m_Height);

	//回転の基準点の計算
	m_WrongTarget.anchor.x = (float)m_WrongTarget.GetTextureWidth() / 2.0f;
	m_WrongTarget.anchor.y = (float)m_WrongTarget.GetTextureHeight() / 2.0f;

	//描画範囲
	m_WrongTarget.rect.top = 0;
	m_WrongTarget.rect.left = 0;
	m_WrongTarget.rect.bottom = m_WrongTarget.rect.top + aqua::GetWindowHeight();
	m_WrongTarget.rect.right = m_WrongTarget.rect.left + aqua::GetWindowWidth();

	//当たり半径の計算
	m_HitRadius = (float)m_WrongTarget.GetTextureWidth() / 3.0f;

	//速度の計算
	m_Velocity = aqua::CVector2(aqua::Rand(m_max_speed, m_min_speed), aqua::Rand(m_max_speed, m_min_speed));
}

//更新
void CWrongTarget::Update(void)
{	
	CheckHitMouse();
	//位置の計算
	m_Position += m_Velocity * aqua::GetDeltaTime();

	float w = (float)aqua::GetWindowWidth() - m_WrongTarget.GetTextureWidth();
	float h = (float)aqua::GetWindowHeight() - m_WrongTarget.GetTextureHeight();

	//壁判定
	if (m_Position.x < 0.0f)
	{
		m_Position.x = 0.1f - m_Position.x;
		m_Velocity.x *= -1.0f;
	}
	if (m_Position.x > w)
	{
		m_Position.x = w - (m_Position.x - w);
		m_Velocity.x *= -1.0f;
	}
	if (m_Position.y < 0.0f)
	{
		m_Position.y = 0.1f - m_Position.y;
		m_Velocity.y *= -1.0f;
	}
	if (m_Position.y > h)
	{
		m_Position.y = h - (m_Position.y - h);
		m_Velocity.y *= -1.0f;
	}


	m_WrongTarget.position = m_Position;
}

//描画
void CWrongTarget::Draw(void)
{
	m_WrongTarget.Draw();
}

//解放
void CWrongTarget::Finalize(void)
{
	m_WrongTarget.Delete();
}

void CWrongTarget::CheckHitMouse(void)
{
	if (!aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
	}

	aqua::CPoint p = aqua::mouse::GetCursorPos();

	aqua::CVector2 mpos = aqua::CVector2((float)p.x, (float)p.y);

	aqua::CVector2 v = m_WrongTarget.position + aqua::CVector2(m_WrongTarget.GetTextureWidth() / 2.0f, m_WrongTarget.GetTextureHeight() / 3.0f) - mpos;
}
