#pragma once
#include "aqua.h"

class CFinishMessage :public aqua::IGameObject
{
public:
	//コンストラクタ
	CFinishMessage(aqua::IGameObject* parent);

	//デストラクタ
	~CFinishMessage() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;
private:
	aqua::CSprite	m_FinishMessage;
};