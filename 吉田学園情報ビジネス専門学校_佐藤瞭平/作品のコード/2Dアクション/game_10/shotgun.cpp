//=============================================================================
//
// 弾の処理 [bullet.cpp]
// Author : 佐藤瞭平
//
//=============================================================================
#include"shotgun.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"
#include"player.h"
#include"effect.h"
#include"bullet.h"

/*やりたいこと*/
/*弾の回転　←いるのか？
チャージショット
チャージショットで弾の拡大*/

//=============================================================================
// 静的メンバ関数の宣言
//=============================================================================
bool CShotgun::m_bUse = false;
CBullet * CShotgun::m_pBullet[3] = {};

//=============================================================================
// 弾のコンストラクタ
//=============================================================================
CShotgun::CShotgun(int nPriority) : CScene2D(PRIORITY_SOHTGUN)
{
	m_Move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Size = D3DXVECTOR2(0.0f, 0.0f);
	m_nLife = 0;
}


//=============================================================================
// 弾のデストラクタ
//=============================================================================
CShotgun::~CShotgun()
{

}


//=============================================================================
// 弾の生成処理
//=============================================================================
CShotgun *CShotgun::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR2 Size, int nAttack)
{
	CShotgun* pBullet = NULL;

	pBullet = new CShotgun;

	if (pBullet != NULL)
	{
		pBullet->m_Size = Size;
		pBullet->m_Move = move;
		pBullet->Init(pos, Size);
		pBullet->m_bUse = false;
	}
	return pBullet;
}

//=============================================================================
// 弾の初期化処理
//=============================================================================
HRESULT CShotgun::Init(D3DXVECTOR3 pos, D3DXVECTOR2 Size)
{
	m_Pos = pos;

	for (int nCnt = 0; nCnt < 3; nCnt++)
	{
		float fAngle = D3DX_PI * (0.25f * (nCnt+1));
		m_pBullet[nCnt] = CBullet::Create(pos, D3DXVECTOR3(m_Move.x*sinf(fAngle) , m_Move.y* cosf(fAngle), 0.0f), m_Size, 30, true);
	}
	return S_OK;
}	// ポリゴンの初期化処理終了



	//=============================================================================
	// 弾の終了処理
	//=============================================================================
void CShotgun::Uninit(void)
{

	Release();

}// ポリゴンの終了処理終了


 //=============================================================================
 // 弾の更新処理
 //=============================================================================
void CShotgun::Update(void)
{

}// ポリゴンの更新処理終了



 //=============================================================================
 // 弾の描画処理
 //=============================================================================
void CShotgun::Draw(void)
{

}	// ポリゴンの描画処理終了