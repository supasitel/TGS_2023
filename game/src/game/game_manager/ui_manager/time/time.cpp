#include "time.h"
#include "../../message/finish_message/finish_message.h"

const int	CTime::m_default_time_limit = 3;	//制限時間
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
	m_TimerLabel.Create(40, 2);

	//1秒タイマーをセット
	m_OneTimer.Setup(m_one_timer);

	//タイムリミットに制限時間を代入
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

		//ゲームオーバーシーンに移行
		((CSceneManager*)aqua::FindGameObject("SceneManager"))->Change(SCENE_ID::OVER);

	}

}

//描画
void CTime::Draw(void)
{
	//タイマーテキスト
	m_TimerLabel.text = "残り" + std::to_string(m_TimeLimit) + "秒";

	//たーまーテキストの位置
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
	//制限時間が0秒以下なら返す
	return (m_TimeLimit <= 0);
}
