#pragma once
#include "aqua.h"

class CEnemy  :public aqua::IGameObject
{
public:
	//コンストラクタ
	CEnemy (aqua::IGameObject* parent);

	//デストラクタ
	~CEnemy () = default;

	//初期化
	void Initialize(void);

	//更新
	void Update(void);

	//描画
	void Draw(void);

	//解放
	void Finalize(void);
private:
	static const int m_width;
	static const int m_height;
	aqua::CVector2	 m_Position;
	aqua::CVector2	 m_Velocity;
	aqua::CSprite	 m_Enemy;
};