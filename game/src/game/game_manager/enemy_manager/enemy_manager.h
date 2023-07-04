#pragma once
#include "aqua.h"
#include "enemy/enemy_id.h"

class CEnemyManager :public aqua::IGameObject
{
public:
	//コンストラクタ
	CEnemyManager(aqua::IGameObject* parent);

	//デストラクタ
	~CEnemyManager() = default;

	//初期化
	void Initialize(void);

	//更新
	void Update(void);

	//描画
	void Draw(void);

	//解放
	void Finalize(void);

	//エネミー生成
	void Create(ENEMY_ID id);
private:
	static const float m_create_interval;	//生成間隔
	aqua::CTimer	   m_CreateTimer;		//生成タイマー
};