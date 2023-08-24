#include "time.h"

const int	CTime::m_default_time_limit = 30;	//初期の制限時間
const float CTime::m_one_timer = 1.0f;//1秒

//コンストラクタ
CTime::CTime(aqua::IGameObject* parent)
	:IUIManager(parent, "Time")
{
}

//初期化
void CTime::Initialize(void)
{
	//テキストの生成
	m_TimerLabel.Create(35, 2);

	//1秒タイマーをセット
	m_OneTimer.Setup(m_one_timer);

	m_TimeLimit = m_default_time_limit;


}

//更新
void CTime::Update(void)
{
	//終了だったら、返す
	if (Finished())
		return;

	//1秒タイマーの更新
	m_OneTimer.Update();

	//1秒タイマーが終了
	if (m_OneTimer.Finished())
	{
		//タイマーリセット
		m_OneTimer.Reset();

		//１秒ずつ制限時間が減っていく
		--m_TimeLimit;
	}

	//制限時間が0秒になったら
	if (m_TimeLimit == 0)
	{
		//リザルトシーンに移行
		((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::RESULT);
	}
}

//描画
void CTime::Draw(void)
{
	//タイマーテキストの描画
	m_TimerLabel.text = "残り" + std::to_string(m_TimeLimit) + "秒";
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
	return (m_TimeLimit <= 0);
}
