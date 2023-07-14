#include "main_scene.h"
#include "../../../game_manager.h"

//�R���X�g���N�^
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent, "MainScene")
{
}

//������
void CMainScene::Initialize(void)
{
	for (int i = 0; i < 10; ++i)
	{
		aqua::CreateGameObject<CWrongTarget>(this);
	}
	aqua::CreateGameObject<CTime>(this);
	aqua::CreateGameObject<CCurrentTarget>(this);

	IGameObject::Initialize();
}

//�X�V
void CMainScene::Update(void)
{
	IGameObject::Update();
}

//�`��
void CMainScene::Draw(void)
{
	IGameObject::Draw();
}

//���
void CMainScene::Finalize(void)
{
	IGameObject::Finalize();
}
