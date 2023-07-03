#pragma once
#include "aqua.h"
#include "../ui_manager.h"

class CTime :public IUIManager
{
public:
	//コンストラクタ
	CTime(aqua::IGameObject* parent);

	//デストラクタ
	~CTime() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	//終了
	bool Finished(void);
private:
	static const float m_one_timer;		//１秒
	static const int   m_time_limit;	//制限時間	
	aqua::CTimer	   m_Timer;			//１秒タイマー
	aqua::CLabel	   m_TimerLabel;	//タイマーラベル
	int				   m_TimeLimit;		//制限時間
};