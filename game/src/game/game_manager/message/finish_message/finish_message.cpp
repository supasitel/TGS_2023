#include "finish_message.h"

const float CFinishMessage::m_min_scale = 0.0f;		//最小拡大率
const float CFinishMessage::m_max_scale = 1.5f;		//最大拡大率
const float CFinishMessage::m_easing_time = 1.5f;	//イージング時間
const float CFinishMessage::m_view_time = 2.5f;		//メッセージ表示時間

//コンストラクタ
CFinishMessage::CFinishMessage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "FinishMessage")
	,m_ElapsedTime(0.0f)
{
}

//初期化
void CFinishMessage::Initialize(void)
{
	//終了メッセージ
	m_FinishMessage.Create("data\\finish.png");
	m_FinishMessage.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_FinishMessage.GetTextureWidth() / 2.0f;
	m_FinishMessage.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_FinishMessage.GetTextureHeight() / 2.0f;
	m_FinishMessage.anchor.x = (float)m_FinishMessage.GetTextureWidth() / 2.0f;
	m_FinishMessage.anchor.y = (float)m_FinishMessage.GetTextureHeight() / 2.0f;
	m_FinishMessage.scale = aqua::CVector2::ZERO;
}

//更新
void CFinishMessage::Update(void)
{
	//経過時間にデルタタイムを加算
	m_ElapsedTime += aqua::GetDeltaTime();

	//経過時間がメッセージ表示時間を超えたら終了メッセージを削除
	if (m_ElapsedTime > m_view_time)
	{
		DeleteObject();
	}

	//拡大率の時間
	float time = m_ElapsedTime > m_easing_time ? m_easing_time : m_ElapsedTime;

	//拡大率のパラメータ
	float scale = abs(aqua::easing::OutBack(time, m_easing_time, m_min_scale, m_max_scale));

	//終了メッセージの拡大率
	m_FinishMessage.scale = aqua::CVector2(scale, scale);
}

//描画
void CFinishMessage::Draw(void)
{
	m_FinishMessage.Draw();
}

//解放
void CFinishMessage::Finalize(void)
{
	m_FinishMessage.Delete();
}
