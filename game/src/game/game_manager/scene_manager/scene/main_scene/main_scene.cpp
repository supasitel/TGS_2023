#include "main_scene.h"
#include "../../../unit_manager/unit_manager.h"

//�R���X�g���N�^
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent, "MainScene")
{
}

//������
void CMainScene::Initialize(void)
{
	CUnitManager* um = (CUnitManager*)aqua::CreateGameObject<CUnitManager>(this);

	//�s�����^�[�Q�b�g��10�̐���
	for (int i = 0; i < 10; ++i)
	{
		um->Create(CUnitManager::UNIT_ID::WRONG);
	}

	um->Create(CUnitManager::UNIT_ID::CURRENT);

	IGameObject::Initialize();
}

//�X�V
void CMainScene::Update(void)
{
	IGameObject::Update();
}
