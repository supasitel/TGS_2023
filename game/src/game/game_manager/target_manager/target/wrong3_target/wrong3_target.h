#pragma once
#include "../../../unit/unit.h"
#include "aqua.h"

class CWrong3 :public IUnit
{
public:
	//コンストラクタ
	CWrong3(aqua::IGameObject* parent);

	//デストラクタ
	~CWrong3() = default;

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
};