#include "main_scene.h"
#include "../../../enemy/enemy.h"

//�R���X�g���N�^
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

//������
void CMainScene::Initialize(void)
{
	m_GBackGround.Create("data\\magic_circle.png");
	m_GBackGround.position = aqua::CVector2::ZERO;

	CEnemy* enemy = (CEnemy*)aqua::CreateGameObject<CEnemy>(this);
}

//�X�V
void CMainScene::Update(void)
{
}

//�`��
void CMainScene::Draw(void)
{
	m_GBackGround.Draw();
}

//���
void CMainScene::Finalize(void)
{
	m_GBackGround.Delete();
}
