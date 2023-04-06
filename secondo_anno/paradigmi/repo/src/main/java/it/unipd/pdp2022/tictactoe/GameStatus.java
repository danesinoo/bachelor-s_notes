package it.unipd.pdp2022.tictactoe;

public enum GameStatus {
  ONGOING(false),
  TIE(true),
  PLAYER_O_WON(true),
  PLAYER_X_WON(true);

  public final boolean done;

  GameStatus(boolean done) {
    this.done = done;
  }
}
