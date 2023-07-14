#pragma once
#include "aqua.h"

class ITarget :public aqua::IGameObject
{
public:
	//コンストラクタ
	ITarget(aqua::IGameObject* parent,const std::string&name);

	//デストラクタ
	~ITarget() = default;

	//初期化
	void Initialize(void);

	//更新
	void Update(void);

	//描画
	void Draw(void);

	//解放
	void Finalize(void);

	//幅取得
	int GetWidth(void);

	//高さ取得
	int GetHeight(void);

	//半径取得
	float GetRadius(void);

	//中心位置取得
	//aqua::CVector2 GetCenterPosition(void);
protected:
	//壁判定
	void CheckHitWall(void);

	int	m_Width;	//幅
	int m_Height;	//高さ
	float m_Radius;	//当たり半径
	aqua::CVector2	m_Position;	//位置
	aqua::CVector2	m_Velocity;	//速度
private:
};