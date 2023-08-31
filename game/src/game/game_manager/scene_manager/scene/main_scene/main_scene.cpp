#include "main_scene.h"
#include "../../../unit/unit.h"
#include "game/game_manager/game_manager.h"

//�R���X�g���N�^
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent, "MainScene")
{
}

//������
void CMainScene::Initialize(void)
{
	//�w�i�̃Q�[���I�u�W�F�N�g����
	(CBackGround*)aqua::CreateGameObject<CBackGround>(this);

	//�^�C�}�[�̃Q�[���I�u�W�F�N�g����
	(CTime*)aqua::CreateGameObject<CTime>(this);

	//�s�����^�[�Q�b�g��10�̐���
	for (int i = 0; i < 10; ++i)
	{
		(CWrongTarget*)aqua::CreateGameObject<CWrongTarget>(this);
	}

	//�����^�[�Q�b�g�̃Q�[���I�u�W�F�N�g����
	(CCurrentTarget*)aqua::CreateGameObject<CCurrentTarget>(this);

	IGameObject::Initialize();
}

//�X�V
void CMainScene::Update(void)
{
	IGameObject::Update();
}
