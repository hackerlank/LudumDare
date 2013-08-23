// a very very basic physics gravity and shit like that

#define GRAVITY 9.81
#define NUM 4
dxMoveSprite *dxSpr[NUM];
bool picked = false,isGround=false;

void physics()
{
	for(int i = 0; i<NUM; i++) // Going over all the sprites
	{
		if(i==1)
			continue;
		if(!( i==2&&picked))
			dxSpr[i]->m_Movement += D3DXVECTOR2(0,GRAVITY/180);

			if(dxSpr[i]->m_Translation.y >= screen_height-(dxSpr[i]->m_SrcRect.bottom-dxSpr[i]->m_SrcRect.top)*dxSpr[i]->m_Scaling.y)
			{
				if(i==0)
					isGround=true;
				dxSpr[i]->m_Movement.y = 0;
			}

		if(i!=0 && dxSpr[0]->isColliding(dxSpr[i])){
			if(i==2){
				picked = true;
				dxSpr[i]->m_Translation = dxSpr[0]->m_Translation;
				dxSpr[i]->m_Translation.y+= 45;
				if(dxSpr[i]->frame==0)
					dxSpr[i]->m_Translation.x+= 15;
				else
					dxSpr[i]->m_Translation.x-= 40;
			}
		}

			for(int j = 0; j<NUM; j++) // Going over all the sprites
			{
				if(j==1 || j==i || i==0&&j==2 || i==2&&j==0)
					continue;
				if(dxSpr[i]->isColliding(dxSpr[j])){
					if(i==0 && 0<dxSpr[i]->m_Translation.y-dxSpr[j]->m_Translation.y<1)
						isGround = true;
					dxSpr[i]->m_Movement.y=0;
				}
			}

		dxSpr[i]->Update(); // Updating 
	}

}
