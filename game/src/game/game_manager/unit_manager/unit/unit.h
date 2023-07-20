#pragma once
#include "aqua.h"

class IUnit :public aqua::IGameObject
{
public:
	//コンストラクタ
	IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category);

	//デストラクタ
	~IUnit() = default;

	//描画
	void Draw(void);

	//解放
	void Finalize(void);

	virtual bool Damage(int damage);

	//位置の取得
	aqua::CVector2 GetPosition(void);

	//中心位置の取得
	aqua::CVector2 GetCenterPosition(void);

	//当たり半径の取得
	float GetHitRadius(void);

	int GetLife(void);

	int GetMaxLife(void);

	//壁判定
	void CheckHitWall(void);
protected:
	//状態ID
	enum class STATE
	{
		LIVE,
		DEAD,
	};

	static const int m_default_max_life;
	static const float m_dead_time;
	static const int m_MaxLife;
	aqua::CSprite m_UnitSprite;
	aqua::CVector2 m_Position;
	aqua::CVector2 m_Velocity;
	aqua::CTimer	m_DeadTimer;
	float m_HitRadius;
	int m_Life;
	
	STATE	m_State;
	
};