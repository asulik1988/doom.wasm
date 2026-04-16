/*
 * doom_player_pos.c — Player position exports for the wasm bridge.
 *
 * This file lives separately from doom_wasm.c because doom_wasm.c includes
 * doomgeneric.h (which pulls in stdbool.h), and d_player.h includes
 * doomtype.h (which defines boolean with true/false enumerators that
 * conflict with stdbool's macros). Keeping them in separate compilation
 * units avoids the conflict entirely.
 */

#include "d_player.h"
#include "doomdef.h"

/* EXPORT macro — matches doom_wasm.h */
#define EXPORT __attribute__((visibility("default")))

extern player_t players[MAXPLAYERS];
extern int consoleplayer;

/*
 * Player X/Y in fixed-point Doom units (16.16). JS divides by 65536.0.
 * Returns 0 when no player map object exists (title screen, menus, etc.).
 */
EXPORT int32_t getPlayerX(void) {
  if (!players[consoleplayer].mo) return 0;
  return (int32_t)players[consoleplayer].mo->x;
}

EXPORT int32_t getPlayerY(void) {
  if (!players[consoleplayer].mo) return 0;
  return (int32_t)players[consoleplayer].mo->y;
}
