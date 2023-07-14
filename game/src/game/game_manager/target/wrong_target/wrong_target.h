#pragma once
#include "aqua.h"
#include "../target.h"

class CWrongTarget :public ITarget
{
public:
	//�R���X�g���N�^
	CWrongTarget(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CWrongTarget() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	//�F
	void SetColor(const aqua::CColor&& color);

	static const unsigned int		m_clicked_color;			//�N���b�N���̐F
	static const unsigned int		m_default_color;			//�I��O�̐F
	static const int				m_height;					//��
	static const int 				m_width;					//����
	static const float				m_radius;					//
	static const float				m_max_velocity;				//
	static const float				m_min_velocity;				//

	aqua::CSprite					m_WrongTarget;				//�^�[�Q�b�g(�ԈႢ)
};