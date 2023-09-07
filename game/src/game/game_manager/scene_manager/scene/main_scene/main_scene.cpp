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
	CTime*time=aqua::CreateGameObject<CTime>(this);
	//�^�C�}�[�̏�Ԃ�wait�ɂ���
	time->SetGameObjectState(aqua::GAME_OBJECT_STATE::WAIT);

	//�s�����^�[�Q�b�g�𐶐�
	for (int i = 0; i < 50; ++i)
	{
		(CWrongTarget*)aqua::CreateGameObject<CWrongTarget>(this);
	}
	
	//�����^�[�Q�b�g�̃Q�[���I�u�W�F�N�g����
	(CCurrentTarget*)aqua::CreateGameObject<CCurrentTarget>(this);

	//�X�^�[�g���b�Z�[�W�̃Q�[���I�u�W�F�N�g����
	aqua::CreateGameObject<CStartMessage>(this)->Initialize();

	IGameObject::Initialize();
}

//�X�V
void CMainScene::Update(void)
{
	//�X�^�[�g���b�Z�[�W�̕\�����I������琧�����Ԃ�active�ɂ���
	if (!FindChild("StartMessage"))
	{
		CTime*time=(CTime*)aqua::FindGameObject("Time");
		time->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);
	}
	IGameObject::Update();
}
