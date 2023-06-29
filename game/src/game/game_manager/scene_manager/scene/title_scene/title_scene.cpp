#include "title_scene.h"

//�R���X�g���N�^
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent,"TitleScene")
{
}

//������
void CTitleScene::Initialize(void)
{
	m_BackGround.Create("data\\magic_circle.png");
}

//�X�V
void CTitleScene::Update(void)
{
	using namespace aqua::keyboard;

	if (Trigger(KEY_ID::SPACE))
	{
		Change(SCENE_ID::MAIN);
	}
}

//�`��
void CTitleScene::Draw(void)
{
	m_BackGround.Draw();
}

//���
void CTitleScene::Finalize(void)
{
	m_BackGround.Delete();
}
