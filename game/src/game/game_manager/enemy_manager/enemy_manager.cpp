#include "enemy_manager.h"
#include "enemy/enemy.h"

const float CEnemyManager::m_create_interval = 0.75;	//生成間隔

//コンストラクタ
CEnemyManager::CEnemyManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"EnemyManager")
{
}

//初期化
void CEnemyManager::Initialize(void)
{
	//生成タイマーの初期化
	m_CreateTimer.Setup(m_create_interval);

	IGameObject::Initialize();
}

//更新
void CEnemyManager::Update(void)
{
	//生成タイマーの更新
	m_CreateTimer.Update();

	//生成タイマーが終了したら
	if (m_CreateTimer.Finished())
	{
		//生成タイマーをリセットする
		m_CreateTimer.Reset();

		//エネミー1を生成
		Create(ENEMY_ID::ENEMY1);
	}
	IGameObject::Update();
}

//描画
void CEnemyManager::Draw(void)
{
	IGameObject::Draw();
}

//解放
void CEnemyManager::Finalize(void)
{
	IGameObject::Finalize();
}

//エネミー生成
void CEnemyManager::Create(ENEMY_ID id)
{
}
