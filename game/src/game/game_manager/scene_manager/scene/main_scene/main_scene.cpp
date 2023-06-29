#include "main_scene.h"
#include "../../../enemy/enemy.h"
#include "../../../target/target.h"


//�R���X�g���N�^
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

//������
void CMainScene::Initialize(void)
{
	CTarget* target = aqua::CreateGameObject<CTarget>(this);
}

//�X�V
void CMainScene::Update(void)
{
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
