#define UNICODE
#define _UNICODE

#include <iostream>
#include <thread>
#include <vector>
#include <stdio.h>
#include <Windows.h>

using namespace std;

wstring tetromino[7];

int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

int nScreenWidth = 80;    //Console Screen Size X (columns)
int nScreenHeight = 30;   //Console Screen Size Y (rows)

int Rotate(int px, int py, int r) {
  switch (r % 4) {
    case 0: return py * 4 + px;        // 0 degrees
    case 1: return 12 + py - (px * 4); // 90 degrees
    case 2: return 15 - (py * 4) - px; // 180 degrees
    case 3: return 3 - py + (px * 4);  // 270 degrees
  }
  return 0;
}

bool DoesPieceFit( int nTetromino, int nRotation, int nPosX, int nPosY) {

  for (int px = 0; px < 4; px++) {
    for (int py = 0; py < 4; py++) {
      //Get index into piece
      int pi = Rotate(px, py, nRotation);

      //Get index into field
      int fi = (nPosY + py) * nFieldWidth + (nPosX + px);

      if (nPosX + px >= 0 && nPosX + px < nFieldWidth) {
        if (nPosY + py >= 0 && nPosY + py < nFieldHeight) {
          if (tetromino[nTetromino][pi] == L'X' && pField[fi] != 0)
            return false; //fail on first hit
        }
      }
    }
  }

  return true;
}

int main() {
  //Create assets
  tetromino[0].append(L"..X.");
  tetromino[0].append(L"..X.");
  tetromino[0].append(L"..X.");
  tetromino[0].append(L"..X.");

  tetromino[1].append(L"..X.");
  tetromino[1].append(L".XX.");
  tetromino[1].append(L".X..");
  tetromino[1].append(L"....");

  tetromino[2].append(L".X..");
  tetromino[2].append(L".XX.");
  tetromino[2].append(L"..X.");
  tetromino[2].append(L"....");

  tetromino[3].append(L"....");
  tetromino[3].append(L".XX.");
  tetromino[3].append(L".XX.");
  tetromino[3].append(L"....");

  tetromino[4].append(L"..X.");
  tetromino[4].append(L".XX.");
  tetromino[4].append(L"..X.");
  tetromino[4].append(L"....");

  tetromino[5].append(L"....");
  tetromino[5].append(L".XX.");
  tetromino[5].append(L"..X.");
  tetromino[5].append(L"..X.");

  tetromino[6].append(L"....");
  tetromino[6].append(L".XX.");
  tetromino[6].append(L".X..");
  tetromino[6].append(L".X..");


  pField = new unsigned char[nFieldWidth*nFieldHeight]; //Create play field buffer
  for (int x = 0; x < nFieldWidth; x++) //Board boundary
    for (int y = 0; y < nFieldHeight; y++)
      pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth -1 || y == nFieldHeight -1) ? 9 : 0;

  wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
  for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
  HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0 , NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
  SetConsoleActiveScreenBuffer(hConsole);
  DWORD dwBytesWritten = 0;

  bool bGameOver = false;

  int nCurrentPiece = 1;
  int nCurrentRotation = 0;
  int nCurrentX = nFieldWidth / 2;
  int nCurrentY = 0;

  bool bKey[4];
  bool bRotateHold = false;

  int nSpeed = 20;
  int nSpeedCounter = 0;
  bool bForceDown = false;
  int nPieceCount = 0;
  int nScore = 0;

  vector<int> vLines;


  while (!bGameOver) {
    // Game Timing
    Sleep(50); // Game Tick
    nSpeedCounter++;
    bForceDown = (nSpeedCounter == nSpeed);


    // Input
    for (int k = 0; k < 4; k++)                            //R   L   D  Z
      bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;

    // Game Logic
    nCurrentX -= (bKey[1] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY)) ? 1 : 0; //Left
    nCurrentX += (bKey[0] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0; //Right
    nCurrentY += (bKey[2] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) ? 1 : 0; //Down

    if (bKey[3]) {
      nCurrentRotation += (!bRotateHold && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 : 0; //Rotate
      bRotateHold = true;
    } else bRotateHold = false;

    if (bForceDown) {
      if (DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
        nCurrentY++; //Force the piece down
      else {
        //Lock piece in field
        for (int px = 0; px < 4; px++)
          for (int py = 0; py < 4; py++)
            if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
              pField[(nCurrentY + py) * nFieldWidth + (nCurrentX + px)] = nCurrentPiece + 1;

        nPieceCount++;
        if (nPieceCount % 10 == 0)
          if (nSpeed >= 10) nSpeed--;

        //Check have we created horizontal lines
        for (int py = 0; py < 4; py++)
          if (nCurrentY + py < nFieldHeight - 1) {
            bool bLine = true;
            for (int px = 1; px < nFieldWidth - 1; px++)
              bLine &= (pField[(nCurrentY + py) * nFieldWidth + px]) != 0;

            if (bLine) {
              //Remove line, display = symbols
              for (int px = 1; px < nFieldWidth - 1; px++)
                pField[(nCurrentY + py) * nFieldWidth + px] = 8;

              vLines.push_back(nCurrentY + py);
            }
          }

        nScore += 25;
        if (!vLines.empty()) nScore += (1 << vLines.size()) * 100;

        // Choose next piece
        nCurrentX = nFieldWidth / 2; //Middle of field
        nCurrentY = 0; //Top of field
        nCurrentRotation = 0; //Default orientation
        nCurrentPiece = rand() % 7; //Random piece

        // If piece does not fit

        bGameOver = !DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY);
      }

      nSpeedCounter = 0;
    }

    // Render Output

    //Draw field
    for (int x = 0; x < nFieldWidth; x++)
      for (int y = 0; y < nFieldHeight; y++)
        screen[(y + 2)*nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y*nFieldWidth + x]];

    //Draw Current Piece
    for (int px = 0; px < 4; px++)
      for (int py = 0; py < 4; py++)
        if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
          screen[(nCurrentY + py + 2)*nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;

    //Draw Score
    swprintf(&screen[2 * nScreenWidth + nFieldWidth + 6], L"SCORE: %8d", nScore);

    if (!vLines.empty()) {
      // Display Frame
      WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
      Sleep(400);

      for (auto &v : vLines)
        for (int px = 1; px < nFieldWidth - 1; px++) {
          for (int py = v; py > 0; py--)
            pField[py * nFieldWidth + px] = pField[(py - 1) * nFieldWidth + px];
          pField[px] = 0;
        }
      vLines.clear();

    }

    //Display Frame
    WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
  }

  // DONE
  CloseHandle(hConsole);
  cout << "GAME OVER.  Score: " << nScore << endl;
  system("pause");




  return 0;
}
