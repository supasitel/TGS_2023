#include "target_manager.h"
#include "target/wrong_target/wrong_target.h"

CTargetManager::CTargetManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"TargetManager")
{
}

void CTargetManager::Initialize(void)
{

}

void CTargetManager::Update(void)
{

	IGameObject::Update();
}

void CTargetManager::Create(TARGET_ID id)
{
	IGameObject* target = nullptr;

	switch (id)
	{
	case TARGET_ID::WRONG_TARGET: target = aqua::CreateGameObject<CWrongTarget>(this);	break;
	}
	target->Initialize();
}

