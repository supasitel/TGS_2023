#include "score.h"

const int CScore::m_max_score = 9999;	//最大スコア
const int CScore::m_min_score = 0;		//最少スコア

//コンストラクタ
CScore::CScore(aqua::IGameObject* parent)
	:IUIManager(parent, "Score")
	,m_Score(0)
{
}

//初期化
void CScore::Initialize(void)
{
	//スコアラベル生成
	m_ScoreLabel.Create(36, 2);

	IUIManager::Initialize();
}

//更新
void CScore::Update(void)
{
	//スコアラベルテキスト
	m_ScoreLabel.text = "スコア" + std::to_string(m_Score);

	//スコアラベル位置
	m_ScoreLabel.position = { 500.0f,0.0f };
}

//描画
void CScore::Draw(void)
{
	m_ScoreLabel.Draw();
}

//解放
void CScore::Finalize(void)
{
	m_ScoreLabel.Delete();
}

//スコアの加算
void CScore::Add(int score)
{
	m_Score += score;

	//スコアの上下限チェック
	if (m_Score < m_min_score)
		m_Score = m_min_score;
	else if (m_Score > m_max_score)
		m_Score = m_max_score;
}

//スコアのクリア
void CScore::Clear(void)
{
	//スコアを0にする
	m_Score = 0;
}

//スコアの取得
int CScore::GetScore(void) const
{
	//スコアを返す
	return m_Score;
}
