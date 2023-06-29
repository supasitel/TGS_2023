#pragma once
#include "aqua.h"

class CScore :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CScore(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CScore() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	static const int m_max_score;	//�ő�X�R�A
	static const int m_min_score;	//�ŏ��X�R�A
	int				 m_Score;		//�X�R�A
	aqua::CLabel	 m_ScoreLabel;	//�X�R�A���x��
};