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
	static const int m_width;		//2��ނ̃{�^���̕�
	static const int m_height;		//2��ނ̃{�^���̍���

	aqua::CLabel	m_Title;		//�^�C�g�����x��
	aqua::CLabel	m_Message;		//���b�Z�[�W���x��
	aqua::CSprite	m_BackGround;	//�w�i�X�v���C�g
	aqua::CSprite	m_Button;		//�{�^���X�v���C�g
	aqua::CSprite	m_ButtonBlack;	//�{�^���i�����j�X�v���C�g

};
