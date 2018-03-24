void mapping(t_param *p)
{
 int x;
 double

 x = 0;
 while (x < p->width)
 {

  x++;
 }
}












for(int x = 0; x < w; x++)
    {
      ///calcul de la position et de l'orientation du rayon
      double cameraX = 2 * x / double(w) - 1; ///Coordonner x dans l'espace de la camera
      double rayPosX = posX;				 ///  Coordonner x de rayon dans l'espace
      double rayPosY = posY;                 /// Coordonner y de rayon dans l'espace
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      ///Dans quelle case de la carte, nous nous situons au debut
      int mapX = int(rayPosX);
      int mapY = int(rayPosY);

      ///Longueur des rayons de la position actuelle au prochain x ou y
      double distMurX; ///Distance entre le joueur et 1e prochain mur vertical
      double distMurY; ///Distance entre le joueur et 1e prochain mur horizontal

       ///Longueur des rayons de la position  du x ou y actuel au prochain x ou y
      double dist2MurX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX)); ///Distance entre deux murs verticaux
      double dist2MurY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY)); ///Distance entre deux murs horizontaux
      double longueurMur;
