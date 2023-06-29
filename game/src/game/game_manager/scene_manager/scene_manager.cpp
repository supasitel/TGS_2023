#include "scene_manager.h"
#include "scene/title_scene/title_scene.h"
#include "scene/main_scene/main_scene.h"
#include "scene/result_scene/result_scene.h"

const float CSceneManager::m_fade_speed = 250.0f;	//フェード速度

//コンストラクタ
CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "SceneManager")
	, m_CurrentSceneID(SCENE_ID::DUMMY)
	, m_NextSceneID(SCENE_ID::DUMMY)
	, m_PushSceneID(SCENE_ID::DUMMY)
	, m_State(STATE::SCENE_IN)
	, m_PushFlag(false)

{
}

//初期化
void CSceneManager::Initialize(void)
{
	//フェードプレーンのセットアップ
	m_FadePlane.Setup(aqua::CVector2::ZERO, (float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight(), aqua::CColor::BLACK);

	//タイトルシーンIDの生成
	Create(SCENE_ID::TITLE);

	//状態をシーン開始にする
	m_State = STATE::SCENE_IN;

	//スタックフラグにfalseを入れる
	m_PushFlag = false;


}

//更新
void CSceneManager::Update(void)
{
	switch (m_State)
	{
	case STATE::SCENE_IN:		SceneIn();		break;
	case STATE::SCENE_UPDATE:	SceneUpdate();	break;
	case STATE::SCENE_OUT:		SceneOut();		break;
	case STATE::SCENE_CHANGE:	ScneChange();	break;
	}
}

//描画
void CSceneManager::Draw(void)
{
	IGameObject::Draw();

	//フェードプレーンの描画
	m_FadePlane.Draw();
}

//解放
void CSceneManager::Finalize(void)
{
	IGameObject::Finalize();
}

//変更
void CSceneManager::Change(SCENE_ID id)
{
	//次のシーンに変更
	m_NextSceneID = id;
}

//スタック
void CSceneManager::Push(SCENE_ID id)
{
	//同じフレーム中にすでにプッシュされている
	if (m_PushFlag || m_PushSceneID != SCENE_ID::DUMMY)
		return;

	//スタックフラグをtrueにする
	m_PushFlag = true;

	//スタックするシーンID
	m_PushSceneID = id;
}

//取り出し
void CSceneManager::Eject(void)
{
	//子のシーンが１つの場合ポップできない
	if (m_ChildObjectList.size() <= 1)
		return;

	// 末尾のシーンのイテレータ取得
	aqua::GAME_OBJECT_LIST::reverse_iterator it = m_ChildObjectList.rbegin();

	// シーンクラスにキャスト
	IScene* scene = (IScene*)(*it);

	//シーンを削除する
	scene->DeleteObject();

	// ひとつ前のシーンを取得
	scene = (IScene*)(*(++it));

	//シーンの状態をACTIVEにする
	scene->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);
}

//リセット
void CSceneManager::Reset(void)
{
	m_NextSceneID = m_CurrentSceneID;

	m_CurrentSceneID = SCENE_ID::DUMMY;
}

//生成
void CSceneManager::Create(SCENE_ID id)
{
	IScene* scene = nullptr;

	// idごとに新しくシーンを生成
	switch (id)
	{
	case SCENE_ID::TITLE:		scene = aqua::CreateGameObject<CTitleScene>(this); break;
	case SCENE_ID::MAIN:		scene = aqua::CreateGameObject<CMainScene>(this); break;
	}

	AQUA_ASSERT(scene, "シーンが生成できませんでした。");

	scene->Initialize();
	scene->Update();
}

//削除
void CSceneManager::Delete(void)
{
	IGameObject::Finalize();
}

//シーン開始
void CSceneManager::SceneIn(void)
{
	//アルファ値の計算
	float alpha = (float)m_FadePlane.color.alpha;
	alpha -= m_fade_speed * aqua::GetDeltaTime();

	//アルファ値が0より小さかったら
	if (alpha < 0.0f)
	{
		//アルファ値を0にする
		alpha = 0.0f;

		//シーンを更新する
		m_State = STATE::SCENE_UPDATE;
	}
	//フェードプレーンの色のアルファ値
	m_FadePlane.color.alpha = (unsigned char)alpha;
}

//シーン更新
void CSceneManager::SceneUpdate(void)
{
	//プッシュ処理中
	if (m_PushFlag)
	{
		//末尾のシーンのイテレータを取得
		aqua::GAME_OBJECT_LIST::reverse_iterator it = m_ChildObjectList.rbegin();

		//シーンクラスにキャスト
		IScene* scene = (IScene*)(*it);

		//シーンを待機状態にする
		scene->SetGameObjectState(aqua::GAME_OBJECT_STATE::WAIT);

		//スタックするシーンIDを生成
		Create(m_PushSceneID);

		//スタックするシーンIDをダミーにする
		m_PushSceneID = SCENE_ID::DUMMY;

		//スタックフラグをfalseにする
		m_PushFlag = false;
	}

	IGameObject::Update();

	//シーン変更の検知
	if (m_CurrentSceneID != m_NextSceneID)
		m_State = STATE::SCENE_OUT;
}

//シーン終了
void CSceneManager::SceneOut(void)
{
	//アルファ値の計算
	float alpha = (float)m_FadePlane.color.alpha;
	alpha += m_fade_speed * aqua::GetDeltaTime();

	//アルファ値が色の最大値より大きかったら
	if (alpha > (float)aqua::CColor::MAX_COLOR)
	{
		//アルファ値を色の最大値にする
		alpha = (float)aqua::CColor::MAX_COLOR;

		//シーン変更
		m_State = STATE::SCENE_CHANGE;
	}
	//フェードプレーンの色のアルファ値
	m_FadePlane.color.alpha = (unsigned char)alpha;

}

//シーン変更
void CSceneManager::ScneChange(void)
{
	//現在のシーンを削除
	Delete();

	//次のシーンIDを生成
	Create(m_NextSceneID);

	//現在のシーンIDに次のシーンIDを代入
	m_CurrentSceneID = m_NextSceneID;

	//シーン状態をシーン開始にする
	m_State = STATE::SCENE_IN;
}