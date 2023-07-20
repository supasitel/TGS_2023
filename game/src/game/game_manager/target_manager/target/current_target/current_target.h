#pragma once
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/unit.h"

class CCurrnetTarget :public IUnit
{
public:
	//コンストラクタ
	CCurrnetTarget(aqua::IGameObject* parent);

	//デストラクタ
	~CCurrnetTarget() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;
private:
};