#include "score.h"

const int CScore::m_max_score = 9999;	//最大スコア
const int CScore::m_min_score = 0;		//最少スコア

//コンストラクタ
CScore::CScore(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Score")
{
}

//初期化
void CScore::Initialize(void)
{
	//スコアラベル
	m_ScoreLabel.Create(36, 2);
}

//更新
void CScore::Update(void)
{
}

//描画
void CScore::Draw(void)
{
}

//解放
void CScore::Finalize(void)
{
	m_ScoreLabel.Delete();
}
