#pragma once
#include "aqua.h"

class CStartMessage :public aqua::IGameObject
{
public:
	//コンストラクタ
	CStartMessage(aqua::IGameObject* parent);

	//デストラクタ
	~CStartMessage() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;
private:
	aqua::CSprite	m_StartMessage;		//スタートメッセージ
	static const float m_min_scale;		//最小拡大率
	static const float m_max_scale;		//最大拡大率
	static const float m_easing_time;	//イージング時間
	static const float m_view_time;		//メッセージ表示時間
	float	m_ElapsedTime;				//経過時間
};