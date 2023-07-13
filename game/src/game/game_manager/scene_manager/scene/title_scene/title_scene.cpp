#include "title_scene.h"

//�R���X�g���N�^
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent,"TitleScene")
{
}

//������
void CTitleScene::Initialize(void)
{
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
}

//���
void CTitleScene::Finalize(void)
{
}
