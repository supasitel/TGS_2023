#include "current_target.h"
#include "../../../sound_manager/sound_manager.h"

const std::string CCurrentTarget::m_category = "CurrentTarget";	//カテゴリー
const std::string CCurrentTarget::m_name = "Current";			//名前
const float CCurrentTarget::m_one_timer = 1.0f;					//1秒
const float CCurrentTarget::m_max_speed = 100.0f;				//最高速度
const float CCurrentTarget::m_min_speed = 20.0f;				//最低速度
const int   CCurrentTarget::m_width = 100.0f;					//幅
const int   CCurrentTarget::m_height = 138.0f;					//高さ

//コンストラクタ
CCurrentTarget::CCurrentTarget(aqua::IGameObject* parent)
	:IUnit(parent, m_name, m_category)
	, m_Width(m_width), m_Height(m_height), m_CurrentTarget_Count(1)
{
}

//初期化
void CCurrentTarget::Initialize(void)
{
	//正解ターゲットの生成
	m_CurrentTarget.Create("data\\current.png");

	//位置の代入
	m_Position = m_CurrentTarget.position;

	//ランダムの位置に生成
	m_Position.x = aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = aqua::Rand(aqua::GetWindowHeight() - m_Height);

	//回転の基準点
	m_CurrentTarget.anchor.x = (float)m_CurrentTarget.GetTextureWidth() / 2.0f;
	m_CurrentTarget.anchor.y = (float)m_CurrentTarget.GetTextureHeight() / 2.0f;

	//描画範囲
	m_CurrentTarget.rect.top = 0;
	m_CurrentTarget.rect.left = 0;
	m_CurrentTarget.rect.bottom = m_CurrentTarget.rect.top + aqua::GetWindowHeight();
	m_CurrentTarget.rect.right = m_CurrentTarget.rect.left + aqua::GetWindowWidth();

	//当たり半径
	m_HitRadius = (float)m_CurrentTarget.GetTextureWidth() / 3.0f;

	//速度
	m_Velocity = aqua::CVector2(aqua::Rand(m_max_speed, m_min_speed), aqua::Rand(m_max_speed, m_min_speed));
}

//更新
void CCurrentTarget::Update(void)
{
	//aqua::mouseの省略化
	using namespace aqua::mouse;

	//マウスの座標取得
	aqua::CPoint mpos = GetCursorPos();

	//位置の計算
	m_Position += m_Velocity * aqua::GetDeltaTime();

	float w = (float)aqua::GetWindowWidth() - m_CurrentTarget.GetTextureWidth();
	float h = (float)aqua::GetWindowHeight() - m_CurrentTarget.GetTextureHeight();

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

	//正解ターゲットの位置に代入
	m_CurrentTarget.position = m_Position;

	//マウスカーソルが外側にある場合
	if (mpos.x<m_CurrentTarget.position.x || mpos.x>m_CurrentTarget.position.x + m_width ||
		mpos.y<m_CurrentTarget.position.y || mpos.y>m_CurrentTarget.position.y + m_height)
	{
	}
	else
	{
		//正解ターゲットをクリックしたらゲームクリアシーンに移行
		if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
		{
			CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

			//ターゲットクリック音を再生
			if (sound)sound->Play(SOUND_ID::TCLICK);

			((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::CLEAR);
		}
	}
}

//描画
void CCurrentTarget::Draw(void)
{
	m_CurrentTarget.Draw();
}

//解放
void CCurrentTarget::Finalize(void)
{
	m_CurrentTarget.Delete();
}