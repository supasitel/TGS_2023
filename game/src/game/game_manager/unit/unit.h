#pragma once
#include "aqua.h"

class IUnit :public aqua::IGameObject
{
public:
	//コンストラクタ
	IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category);

	//デストラクタ
	~IUnit() = default;

	//位置の取得
	aqua::CVector2 GetPosition(void);

	//当たり半径の取得
	float GetHitRadius(void);
protected:
	aqua::CVector2 m_Position;	//位置
	aqua::CVector2 m_Velocity;	//速度
	float m_HitRadius;			//当たり半径
};