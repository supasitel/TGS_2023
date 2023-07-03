#include "time.h"

const float CTime::m_one_timer = 1.0;	//１秒
const int   CTime::m_time_limit = 60;	//制限時間

//コンストラクタ
CTime::CTime(aqua::IGameObject* parent)
	:IUIManager(parent,"Time")
{
}

//初期化
void CTime::Initialize(void)
{
	//タイマーラベル生成
	m_TimerLabel.Create(36, 2);

	//タイマー設定
	m_Timer.Setup(m_one_timer);

	//制限時間代入
	m_TimeLimit = m_time_limit;

	IUIManager::Initialize();
}

//更新
void CTime::Update(void)
{
	//終了したら返す
	if (Finished())
		return;

	//１秒タイマーの更新
	m_Timer.Update();

	//１秒タイマーが終了したら
	if (m_Timer.Finished())
	{
		//１秒タイマーをリセット
		m_Timer.Reset();

		//制限時間を１ずつ減らす
		--m_TimeLimit;
	}
}

//描画
void CTime::Draw(void)
{
	//タイマーラベルテキスト
	m_TimerLabel.text = "残り" + std::to_string(m_TimeLimit) + "秒";
	
	//タイマーラベル位置
	m_TimerLabel.position = { 800.0f,0.0f };

	m_TimerLabel.Draw();
}

//解放
void CTime::Finalize(void)
{
	m_TimerLabel.Delete();
}

//終了
bool CTime::Finished(void)
{
	//制限時間が０秒以下になったら返す
	return (m_TimeLimit <= 0);
}
