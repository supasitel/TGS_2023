#include "main_scene.h"
#include "../../../game_manager.h"

//�R���X�g���N�^
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

//������
void CMainScene::Initialize(void)
{
	aqua::CreateGameObject<CScore>(this);
	aqua::CreateGameObject<CTime>(this);
	aqua::CreateGameObject<CWrongTarget>(this);

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
