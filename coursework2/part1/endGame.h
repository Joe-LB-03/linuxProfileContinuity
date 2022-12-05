int winGame( Game *game, char symbol, int x, int y);

int drawGame( Game *game );

int checkVertical(Game *game, int x, int y, char symbol);

int checkHorizontal(Game *game, int x, int y, char symbol);

int checkDiagonalDownRight(Game *game, int x, int y, char symbol);

int checkDiagonalDownLeft(Game *game, int x, int y, char symbol);

