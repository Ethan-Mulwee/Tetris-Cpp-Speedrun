#ifndef TETRIS_TETROMINOS
#define TETRIS_TETROMINOS

#include <raylib.h>

struct Tetromino {
  char shape[4][4];
  inline void Draw(int x, int y, int scale, Color* colors) {
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 4; i++) {
        DrawRectangle(x,y,scale,scale,colors[shape[i][j]]);
        DrawRectangle(x+2,y+2,scale-4,scale-4,ColorBrightness(colors[shape[i][j]],-0.1f));
      }
    }
  }
  inline void Rotate(int r) {
    Tetromino result;
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 4; i++) {
        // transposes for the moment
        result.shape[i][j] = shape[j][3-i];
      }
    }
    *this = result;
  }
  inline Tetromino Rotated(int r) {
    Tetromino result;
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 4; i++) {
        // transposes for the moment
        result.shape[i][j] = shape[j][3-i];
      }
    }
    return result;
  }
};

inline Tetromino tetrominos[7] = {
  // o
  Tetromino {
    0,0,0,0,
    0,2,2,0,
    0,2,2,0,
    0,0,0,0
  },
  // i
  Tetromino {
    0,0,3,0,
    0,0,3,0,
    0,0,3,0,
    0,0,3,0
  },
  // s
  Tetromino {
    0,0,0,0,
    0,0,4,4,
    0,4,4,0,
    0,0,0,0
  },
  // z
  Tetromino {
    0,0,0,0,
    5,5,0,0,
    0,5,5,0,
    0,0,0,0
  },
  // L
  Tetromino {
    0,0,0,0,
    0,6,0,0,
    0,6,0,0,
    0,6,6,0
  },
  // J
  Tetromino {
    0,0,0,0,
    0,0,7,0,
    0,0,7,0,
    0,7,7,0
  },
  // T
  Tetromino {
    0,0,0,0,
    0,8,8,8,
    0,0,8,0,
    0,0,0,0
  }
};

#endif