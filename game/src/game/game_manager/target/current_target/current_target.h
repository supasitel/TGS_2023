#pragma once
#include "aqua.h"

class CCurrentTarget :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CCurrentTarget(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CCurrentTarget() = default;

	//������
	void Initialize(void);

	//�X�V
	void Update(void);

	//�`��
	void Draw(void);

	//���
	void Finalize(void);
private:
	//�F
	void SetColor(const aqua::CColor&& color);

	static const int				m_width;
	static const int				m_height;
	static const unsigned int		m_clicked_color;			//�N���b�N���̐F
	static const unsigned int		m_default_color;			//�I��O�̐F
	static const unsigned int		m_selected_color;			//�I�����̐F

	aqua::CSprite					m_CurrentTarget;
};