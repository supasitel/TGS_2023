#include "wrong2_target.h"
#include "../../../sound_manager/sound_manager.h"

const std::string CWrong2::m_name = "Wrong2";			//名前
const std::string CWrong2::m_category = "Wrong2Target";	//カテゴリー
const int CWrong2::m_width = 100;						//幅
const int CWrong2::m_height = 137;						//高さ
const float CWrong2::m_one_timer = 1.0f;				//1秒
const float CWrong2::m_max_speed = 100.0f;				//最高速度
const float CWrong2::m_min_speed = 20.0f;				//最低速度

//コンストラクタ
CWrong2::CWrong2(aqua::IGameObject* parent)
	:IUnit(parent,m_name,m_category)
	,m_Width(m_width),m_Height(m_height)
{
}

//初期化
void CWrong2::Initialize(void)
{
	//ターゲット（はずれ）の生成
	m_Wrong2.Create("data\\wrong2.png");
	//ターゲットの位置
	m_Position = m_Wrong2.position;
	//ランダムな位置に生成
	m_Position.x = aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = aqua::Rand(aqua::GetWindowHeight() - m_Height);

	//回転の基準点
	m_Wrong2.anchor.x = (float)m_Wrong2.GetTextureWidth() / 2.0f;
	m_Wrong2.anchor.y = (float)m_Wrong2.GetTextureHeight() / 2.0f;

	//描画範囲
	m_Wrong2.rect.top = 0;
	m_Wrong2.rect.left = 0;
	m_Wrong2.rect.bottom = m_Wrong2.rect.top + aqua::GetWindowHeight();
	m_Wrong2.rect.right = m_Wrong2.rect.left + aqua::GetWindowWidth();

	//当たり半径の計算
	m_HitRadius = (float)m_Wrong2.GetTextureWidth() / 3.0f;

	//速度の計算
	m_Velocity = aqua::CVector2(aqua::Rand(m_max_speed, m_min_speed), aqua::Rand(m_max_speed, m_min_speed));

}

//更新
void CWrong2::Update(void)
{
	CheckHitMouse();

	//位置の計算
	m_Position += m_Velocity * aqua::GetDeltaTime();

	float w = (float)aqua::GetWindowWidth() - m_Wrong2.GetTextureWidth();
	float h = (float)aqua::GetWindowHeight() - m_Wrong2.GetTextureHeight();

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
	m_Wrong2.position = m_Position;
}

//描画
void CWrong2::Draw(void)
{
	m_Wrong2.Draw();
}

//解放
void CWrong2::Finalize(void)
{
	m_Wrong2.Delete();
}

void CWrong2::CheckHitMouse(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	//左クリックしたらターゲットクリック時のサウンドを再生
	if (Trigger(BUTTON_ID::LEFT))
	{
		CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

		if (sound)sound->Play(SOUND_ID::TCLICK);
	}

	aqua::CPoint p= GetCursorPos();

	aqua::CVector2 mpos = aqua::CVector2((float)p.x, (float)p.y);

	aqua::CVector2 v = m_Wrong2.position + aqua::CVector2(m_Wrong2.GetTextureWidth() / 2.0f, m_Wrong2.GetTextureHeight() / 3.0f) - mpos;

}
