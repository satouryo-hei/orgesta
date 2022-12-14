//=============================================================================
//
// 選択画面の処理 [select.cpp]
// Author : 佐藤瞭平
//
//=============================================================================
#include "select.h"
#include "scene2D.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"
#include"bg.h"
#include"choose_game.h"

//=============================================================================
// 静的メンバ変数の宣言
//=============================================================================
CBg* CSelect::m_pBg = NULL;
CChoose_Game* CSelect::m_pChoose_Game = NULL;

//=============================================================================
// 選択画面のコンストラクタ
//=============================================================================
CSelect::CSelect(int nPriority) : CScene(PRIORITY_NOMAL)
{
}

//=============================================================================
// 選択画面のデストラクタ
//=============================================================================
CSelect::~CSelect()
{

}

//=============================================================================
// 選択画面の初期化処理
//=============================================================================
HRESULT CSelect::Init(D3DXVECTOR3 pos)
{
	m_pBg = CBg::Create(pos, D3DXVECTOR2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2), 14);

	m_pChoose_Game = CChoose_Game::Create(D3DXVECTOR3(0.0f,0.0f,0.0f));
	return S_OK;
}

//=============================================================================
// 選択画面の終了処理
//=============================================================================
void CSelect::Uninit(void)
{
	//if (m_pBg != NULL)
	//{
	//	m_pBg->Uninit();
	//	m_pBg = NULL;
	//}
	//if (m_pChoose_Game != NULL)
	//{
	//	m_pChoose_Game->Uninit();
	//	m_pChoose_Game = NULL;
	//}

	// 解放処理
	CScene::Release();
}

//=============================================================================
// 選択画面の更新処理
//=============================================================================
void CSelect::Update(void)
{

}

//=============================================================================
// 選択画面の描画処理
//=============================================================================
void CSelect::Draw(void)
{

}