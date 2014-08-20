

ID3DXFont *introFont;
ID3DXFont *gameFont;

void setUpText(LPDIRECT3DDEVICE9 gD3dDevice){
	D3DXCreateFont( gD3dDevice, 25, 10, FW_BOLD, 0, true, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &gameFont );
	D3DXCreateFont( gD3dDevice, 50, 20, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Times New Roman"), &introFont );
}


void showText(ID3DXFont* pFont,LPCSTR msg,D3DCOLOR color,float x, float y,float w,float h){
	RECT rct;
	rct.left = x;
	rct.right = x+w;
	rct.top = y;
	rct.bottom = y+h;
	pFont->DrawText(NULL, msg, -1, &rct, 0, color );
}
