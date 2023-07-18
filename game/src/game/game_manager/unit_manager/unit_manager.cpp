#include "unit_manager.h"
#include "../game_manager.h"

//�R���X�g���N�^
CUnitManager::CUnitManager(aqua::IGameObject* parent, const std::string& name)
{
}

//���j�b�g�̐���
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
