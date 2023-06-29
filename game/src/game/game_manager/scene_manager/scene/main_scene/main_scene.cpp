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
	(CTarget*)aqua::CreateGameObject<CTarget>(this);
	(CEnemy*)aqua::CreateGameObject<CEnemy>(this);

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
