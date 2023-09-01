#pragma once
#include "aqua.h"

class CFinishMessage :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CFinishMessage(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CFinishMessage() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	aqua::CSprite	m_FinishMessage;
};