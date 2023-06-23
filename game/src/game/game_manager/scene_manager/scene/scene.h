#pragma once
#include "aqua.h"
#include "scene_id.h"

class IScene :public aqua::IGameObject
{
public:
	//コンストラクタ
	IScene(aqua::IGameObject* parent, const std::string object_name);

	//デストラクタ
	~IScene(void) = default;

	//変更
	void Change(SCENE_ID id);

	//スタック
	void Push(SCENE_ID id);

	//取り出す
	void Eject(void);

	//リセット
	void Reset(void);

private:
	static const std::string	m_scene_category;	//シーンカテゴリー
};