#pragma once
#include "aqua.h"
#include "../../scene_manager/scene_manager.h"
#include "../ui_manager.h"

class CTime :public IUIManager
{
public:
	//コンストラクタ
	CTime(aqua::IGameObject* parent);

	//デストラクタ
	~CTime() = default;

	//初期化
	void Initialize(void);

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	//終了
	bool Finished(void);

private:
	static const int	m_default_time_limit;	//初期時間
	static const float  m_one_timer;			//1秒
	int                 m_TimeLimit;			//制限時間
	aqua::CLabel        m_TimerLabel;			//タイマーラベル
	aqua::CTimer        m_OneTimer;				//1秒タイマー
};