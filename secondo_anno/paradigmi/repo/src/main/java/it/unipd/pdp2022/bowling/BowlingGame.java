package it.unipd.pdp2022.bowling;

import java.util.ArrayList;
import java.util.List;

/**
 * Bowling Kata
 *
 * <p>Approccio "a basso livello"
 */
public class BowlingGame {

  List<Integer> pins;
  String score;

  public BowlingGame(String score) {
    this.pins = read(score);
    this.score = score;
  }

  public int score() {
    int res = 0;

    int i = 0, frame = 1;
    // Quando vero, siamo nel secondo tiro di un frame
    boolean second = false;

    // Primi nove frame
    while (frame < 10) {
      int curr = pins.get(i);
      res += curr;

      if (score.charAt(i) == 'X' && (i < pins.size() - 2)) {
        res += pins.get(i + 1) + pins.get(i + 2);
        frame++;
      } else if (second) {
        if (score.charAt(i) == '/' && (i < pins.size() - 2)) res += pins.get(i + 1);
        second = false;
        frame++;
      } else {
        second = true;
      }

      i++;
    }

    // ultimo frame
    for (; i < pins.size(); i++) res += pins.get(i);

    return res;
  }

  static List<Integer> read(String score) {
    List<Integer> res = new ArrayList<>();
    for (int i = 0; i < score.length(); i++) {
      var ch = score.charAt(i);
      switch (ch) {
        case '-':
          res.add(0);
          break;
        case 'X':
          res.add(10);
          break;
        case '/':
          res.add(10 - res.get(i - 1));
          break;
        default:
          res.add(ch - '0');
      }
    }
    return res;
  }
}
