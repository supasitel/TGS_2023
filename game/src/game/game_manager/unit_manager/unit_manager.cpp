#include "unit_manager.h"
#include "../target_manager/target/wrong_target/wrong_target.h"
#include "../target_manager/target/current_target/current_target.h"
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
	case CUnitManager::UNIT_ID::CURRENT: Unit = aqua::CreateGameObject<CCurrentTarget>(this);
		break;
	default:
		break;
	}
	if (Unit == nullptr)
		return;

	Unit->Initialize();
}
