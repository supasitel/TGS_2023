#pragma once
#include "../../../unit/unit.h"
#include "../../../scene_manager/scene_manager.h"

class CCurrentTarget :public IUnit
{
public:
	//コンストラクタ
	CCurrentTarget(aqua::IGameObject* parent);

	//デストラクタ
	~CCurrentTarget() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

private:
	static const std::string	m_name;		//名前
	static const std::string	m_category;	//カテゴリー
	static const float m_one_timer;			//１秒
	static const float m_max_speed;			//最高速度
	static const float m_min_speed;			//最低速度
	static const int   m_width;
	static const int   m_height;

	int		m_CurrentTarget_Count;	//正解ターゲットの数
	float   m_Width;				//幅
	float	m_Height;				//高さ
	float   m_Speed;				//速度

	aqua::CSprite	m_CurrentTarget;	//正解ターゲットスクリプト
	aqua::CTimer	m_Timer;			//タイマースクリプト
};