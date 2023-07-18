#pragma once
#include "aqua.h"
#include "unit/unit.h"
#include "unit/unit_id.h"

class CUnitManager :public aqua::IGameObject
{
public:
	//コンストラクタ
	CUnitManager(aqua::IGameObject* parent, const std::string& name);

	//デストラクタ
	~CUnitManager() = default;

	//ユニットの生成
	void Create(UNIT_ID id);
private:
};