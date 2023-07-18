#include "unit_manager.h"
#include "../game_manager.h"

//コンストラクタ
CUnitManager::CUnitManager(aqua::IGameObject* parent, const std::string& name)
{
}

//ユニットの生成
void CUnitManager::Create(UNIT_ID id)
{
	IUnit* Unit = nullptr;

	switch (id)
	{
	case UNIT_ID::WRONG: Unit = aqua::CreateGameObject<CWrongTarget>(this);
		break;
	default:
		break;
	}
	if (Unit == nullptr)
		return;

	Unit->Initialize();
}
