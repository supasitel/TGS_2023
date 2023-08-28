#include "main_scene.h"
#include "../../../unit_manager/unit_manager.h"
#include "game/game_manager/game_manager.h"
#include "../../../target_manager/target/current_target/current_target.h"
#include "../../../target_manager/target/wrong_target/wrong_target.h"

//�R���X�g���N�^
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent, "MainScene")
{
}

//������
void CMainScene::Initialize(void)
{
	//CUnitManager* um = (CUnitManager*)aqua::CreateGameObject<CUnitManager>(this);
	(CTime*)aqua::CreateGameObject<CTime>(this);

	//�s�����^�[�Q�b�g��10�̐���
	for (int i = 0; i < 10; ++i)
	{
		(CWrongTarget*)aqua::CreateGameObject<CWrongTarget>(this);
		/*um->Create(CUnitManager::UNIT_ID::WRONG);*/
	}

	(CCurrentTarget*)aqua::CreateGameObject<CCurrentTarget>(this);
	//um->Create(CUnitManager::UNIT_ID::CURRENT);

	IGameObject::Initialize();
}

//�X�V
void CMainScene::Update(void)
{
	if (!FindChild("CurrentTarget"))
	{
		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::CLEAR);
		}
	}

	IGameObject::Update();
}
