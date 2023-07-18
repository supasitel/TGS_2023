#pragma once
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/unit.h"

class CWrongTarget :public IUnit
{
public:
	//コンストラクタ
	CWrongTarget(aqua::IGameObject* parent);

	//デストラクタ
	~CWrongTarget() = default;

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

	int		m_WrongTarget_Count;	//不正解ターゲットの数
	float   m_Width;				//幅
	float	m_Height;				//高さ
	float   m_Speed;				//速度

	aqua::CSprite	m_WrongTarget;
	aqua::CTimer	m_Timer;
};