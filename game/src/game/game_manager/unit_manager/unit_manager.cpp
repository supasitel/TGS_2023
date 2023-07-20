#include "unit_manager.h"
#include "../target_manager/target/wrong_target/wrong_target.h"
//コンストラクタ
CUnitManager::CUnitManager(aqua::IGameObject* parent)
{
}

//ユニットの生成
void CUnitManager::Create(UNIT_ID id)
{
	IUnit* Unit = nullptr;

	switch (id)
	{
	case CUnitManager::UNIT_ID::WRONG: Unit = aqua::CreateGameObject<CWrongTarget>(this);
		break;
	default:
		break;
	}
	if (Unit == nullptr)
		return;

	Unit->Initialize();
}
