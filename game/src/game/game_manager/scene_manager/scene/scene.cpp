#include "scene.h"
#include "../scene_manager.h"

//コンストラクタ
IScene::IScene(aqua::IGameObject* parent, const std::string object_name)
	:aqua::IGameObject(parent, object_name)
{
}

//シーン変更
void IScene::Change(SCENE_ID id)
{
	//シーンマネージャーの取得
	CSceneManager* sm = (CSceneManager*)GetParent();

	//シーン変更
	sm->Change(id);

}

//シーンスタック
void IScene::Push(SCENE_ID id)
{
	//シーンマネージャーの取得
	CSceneManager* sm = (CSceneManager*)GetParent();

	//シーンスタック
	sm->Push(id);

}

//シーンを取り出す
void IScene::Eject(void)
{
	//シーンマネージャーの取得
	CSceneManager* sm = (CSceneManager*)GetParent();

	//シーンを取り出す
	sm->Eject();

}

//シーンリセット
void IScene::Reset(void)
{
	//シーンマネージャーの取得
	CSceneManager* sm = (CSceneManager*)GetParent();

	//シーンのリセット
	sm->Reset();

}
