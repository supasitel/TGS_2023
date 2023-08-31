#pragma once
#include "aqua.h"
#include "../scene.h"

class CMainScene :public IScene
{
public:
	//コンストラクタ
	CMainScene(aqua::IGameObject* parent);

	//デストラクタ
	~CMainScene() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;
private:
};
