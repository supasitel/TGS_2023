#pragma once
#include "../../../unit/unit.h"
#include "aqua.h"

class CWrong2 :public IUnit
{
public:
	//コンストラクタ
	CWrong2(aqua::IGameObject* parent);

	//デストラクタ
	~CWrong2() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	void CheckHitMouse(void);
private:
	static const int m_width;				//幅
	static const int m_height;				//高さ
	static const float m_one_timer;			//１秒
	static const float m_max_speed;			//最高速度
	static const float m_min_speed;			//最低速度
	static const std::string	m_name;		//名前
	static const std::string	m_category;	//カテゴリー

	float   m_Width;				//幅
	float	m_Height;				//高さ
	float   m_Speed;				//速度

	aqua::CSprite	m_Wrong2;
	aqua::CTimer	m_Timer;
};