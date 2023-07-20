#pragma once
#include "aqua.h"
#include "unit/unit.h"

class CUnitManager :public aqua::IGameObject
{
public:
	//ユニットID
	enum class UNIT_ID
	{
		CURRENT,
		WRONG,

		MAX
	};

	//コンストラクタ
	CUnitManager(aqua::IGameObject* parent);

	//デストラクタ
	~CUnitManager() = default;

	//ユニットの生成
	void Create(UNIT_ID id);
private:
};