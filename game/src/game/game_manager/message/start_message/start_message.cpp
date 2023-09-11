#include "start_message.h"

const float CStartMessage::m_min_scale = 0.0f;		//最小拡大率
const float CStartMessage::m_max_scale = 1.5f;		//最大拡大率
const float CStartMessage::m_easing_time = 1.5f;	//イージング時間
const float CStartMessage::m_view_time = 2.0f;		//メッセージ表示時間

//コンストラクタ
CStartMessage::CStartMessage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "StartMessage")
	, m_ElapsedTime(0.0f)
{
}

//初期化
void CStartMessage::Initialize(void)
{
	//スタートメッセージ
	m_StartMessage.Create("data\\start.png");
	m_StartMessage.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_StartMessage.GetTextureWidth() / 2.0f;
	m_StartMessage.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_StartMessage.GetTextureHeight() / 2.0f;
	m_StartMessage.anchor.x = (float)m_StartMessage.GetTextureWidth() / 2.0f;
	m_StartMessage.anchor.y = (float)m_StartMessage.GetTextureHeight() / 2.0f;
	m_StartMessage.scale = aqua::CVector2::ZERO;
}

//更新
void CStartMessage::Update(void)
{
	//経過時間にデルタタイムの加算
	m_ElapsedTime += aqua::GetDeltaTime();

	//経過時間がメッセージ表示時間を超えたらスタートメッセージを削除
	if (m_ElapsedTime > m_view_time)
	{
		DeleteObject();
	}

	//拡大率の時間
	float time = m_ElapsedTime > m_easing_time ? m_easing_time : m_ElapsedTime;

	//拡大率のパラメータ
	float scale = abs(aqua::easing::OutBack(time, m_easing_time, m_min_scale, m_max_scale));

	//スタートメッセージの拡大率
	m_StartMessage.scale = aqua::CVector2(scale, scale);

}

//描画
void CStartMessage::Draw(void)
{
	m_StartMessage.Draw();
}

//解放
void CStartMessage::Finalize(void)
{
	m_StartMessage.Delete();
}
