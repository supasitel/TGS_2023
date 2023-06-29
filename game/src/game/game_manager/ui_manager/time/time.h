#pragma once
#include "aqua.h"

class CTime :public aqua::IGameObject
{
public:
	//コンストラクタ
	CTime(aqua::IGameObject* parent);

	//デストラクタ
	~CTime() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;
private:
	aqua::CTimer	m_Time;
};