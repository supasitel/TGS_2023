#include "wrong3_target.h"
#include "../../../sound_manager/sound_manager.h"

const std::string CWrong3::m_name = "Wrong3";
const std::string CWrong3::m_category = "Wrong3Target";
const int CWrong3::m_width = 100;
const int CWrong3::m_height = 137;
const float CWrong3::m_one_timer = 1.0f;				//1秒
const float CWrong3::m_max_speed = 100.0f;				//最高速度
const float CWrong3::m_min_speed = 20.0f;				//最低速度

//コンストラクタ
CWrong3::CWrong3(aqua::IGameObject* parent)
	:IUnit(parent,m_name,m_category)
{
}

//初期化
void CWrong3::Initialize(void)
{
	//ターゲット(はずれ)の生成
	m_Wrong3.Create("data\\wrong3.png");
	//ターゲットの位置
	m_Position = m_Wrong3.position;
	//ランダムな位置に生成
	m_Position.x = aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = aqua::Rand(aqua::GetWindowHeight() - m_Height);

	//回転の基準点
	m_Wrong3.anchor.x = (float)m_Wrong3.GetTextureWidth() / 2.0f;
	m_Wrong3.anchor.y = (float)m_Wrong3.GetTextureHeight() / 2.0f;

	//描画範囲
	m_Wrong3.rect.top = 0;
	m_Wrong3.rect.left = 0;
	m_Wrong3.rect.bottom = m_Wrong3.rect.top + aqua::GetWindowHeight();
	m_Wrong3.rect.right = m_Wrong3.rect.left + aqua::GetWindowWidth();

	//当たり半径の計算
	m_HitRadius = (float)m_Wrong3.GetTextureWidth() / 3.0f;

	//速度の計算
	m_Velocity = aqua::CVector2(aqua::Rand(m_max_speed, m_min_speed), aqua::Rand(m_max_speed, m_min_speed));
}

//更新
void CWrong3::Update(void)
{
	CheckHitMouse();

	//位置の計算
	m_Position += m_Velocity * aqua::GetDeltaTime();

	float w = (float)aqua::GetWindowWidth() - m_Wrong3.GetTextureWidth();
	float h = (float)aqua::GetWindowHeight() - m_Wrong3.GetTextureHeight();

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
	m_Wrong3.position = m_Position;

}

//描画
void CWrong3::Draw(void)
{
}

//解放
void CWrong3::Finalize(void)
{
}

//マウス判定
void CWrong3::CheckHitMouse(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	//左クリックしたらターゲットクリック時のサウンドを再生
	if (Trigger(BUTTON_ID::LEFT))
	{
		CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

		if (sound)sound->Play(SOUND_ID::TCLICK);
	}

	aqua::CPoint p = GetCursorPos();

	aqua::CVector2 mpos = aqua::CVector2((float)p.x, (float)p.y);

	aqua::CVector2 v = m_Wrong3.position + aqua::CVector2(m_Wrong3.GetTextureWidth() / 2.0f, m_Wrong3.GetTextureHeight() / 3.0f) - mpos;
}
