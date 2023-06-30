#pragma once
#include "aqua.h"

class CScore :public aqua::IGameObject
{
public:
	//コンストラクタ
	CScore(aqua::IGameObject* parent);

	//デストラクタ
	~CScore() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	//スコアの加算
	void Add(int score);

	//スコアのクリア
	void Clear(void);

	//スコアの取得
	int GetScore(void)const;
private:
	static const int m_max_score;	//最大スコア
	static const int m_min_score;	//最少スコア
	int				 m_Score;		//スコア
	aqua::CLabel	 m_ScoreLabel;	//スコアラベル
};