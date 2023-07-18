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

	//位置の取得
	aqua::CVector2 GetPosition(void);

	//中心位置の取得
	aqua::CVector2 GetCenterPosition(void);

	//当たり半径の取得
	float GetHitRadius(void);

	//壁判定
	void CheckHitWall(void);
protected:
	aqua::CSprite m_UnitSprite;
	aqua::CVector2 m_Position;
	aqua::CVector2 m_Velocity;

	float m_HitRadius;
};