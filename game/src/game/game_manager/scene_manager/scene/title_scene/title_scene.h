#pragma once
#include "aqua.h"
#include "../scene.h"

class CTitleScene :public IScene
{
public:
	//�R���X�g���N�^
	CTitleScene(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CTitleScene() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	static const int m_width;
	static const int m_height;

	aqua::CSprite	m_Title;
	aqua::CSprite	m_BackGround;
};
