#include "main_scene.h"
#include "../../../unit/unit.h"
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
	//�^�C�}�[�̐���
	(CTime*)aqua::CreateGameObject<CTime>(this);

	//�s�����^�[�Q�b�g��10�̐���
	for (int i = 0; i < 10; ++i)
	{
		(CWrongTarget*)aqua::CreateGameObject<CWrongTarget>(this);
	}

	//�����^�[�Q�b�g�̐���
	(CCurrentTarget*)aqua::CreateGameObject<CCurrentTarget>(this);

	IGameObject::Initialize();
}

//�X�V
void CMainScene::Update(void)
{
	IGameObject::Update();
}
