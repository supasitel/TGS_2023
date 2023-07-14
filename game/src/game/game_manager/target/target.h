#pragma once
#include "aqua.h"

class ITarget :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	ITarget(aqua::IGameObject* parent,const std::string&name);

	//�f�X�g���N�^
	~ITarget() = default;

	//������
	void Initialize(void);

	//�X�V
	void Update(void);

	//�`��
	void Draw(void);

	//���
	void Finalize(void);

	//���擾
	int GetWidth(void);

	//�����擾
	int GetHeight(void);

	//���a�擾
	float GetRadius(void);

	//���S�ʒu�擾
	//aqua::CVector2 GetCenterPosition(void);
protected:
	//�ǔ���
	void CheckHitWall(void);

	int	m_Width;	//��
	int m_Height;	//����
	float m_Radius;	//�����蔼�a
	aqua::CVector2	m_Position;	//�ʒu
	aqua::CVector2	m_Velocity;	//���x
private:
};