package it.unipd.pdp2022.bowling;

import java.util.ArrayList;
import java.util.List;

/**
 * Bowling Kata
 *
 * <p>Approccio "ultimi tre indici"
 */
public class BowlingGame1 {

  private List<Integer> scores;

  public BowlingGame1(String frames) {
    this.scores = BowlingGame1.read(frames);
  }

  public int score() {
    int frameIdx = 0;
    int frameCount = 0;
    int res = 0;

    // Primi frame
    while (frameCount <= 8) {
      res += frameScore(scores.get(frameIdx), scores.get(frameIdx + 1), scores.get(frameIdx + 2));
      if (scores.get(frameIdx) == 10) frameIdx++;
      else frameIdx += 2;
      frameCount++;
    }

    // Ultimo frame
    if (scores.get(frameIdx) == 10 || scores.get(frameIdx) + scores.get(frameIdx + 1) == 10)
      res += frameScore(scores.get(frameIdx), scores.get(frameIdx + 1), scores.get(frameIdx + 2));
    else res += frameScore(scores.get(frameIdx), scores.get(frameIdx + 1), 0);
    return res;
  }

  // Ritorna il risultato del frame: se i primi due valori sommano inferiori a dieci, il punteggio è
  // costituito da loro due. Se invece sono pari o superiori, il punteggio è dato da tutti e tre.
  private int frameScore(int a, int b, int c) {
    if (a + b < 10) return a + b;
    else return a + b + c;
  }

  public static List<Integer> read(String score) {

    List<Integer> res = new ArrayList<>();

    String scr = score.replace("-", "0");
    res.add(convert('0', scr.charAt(0)));

    for (int i = 1; i < scr.length(); i++) res.add(convert(scr.charAt(i - 1), scr.charAt(i)));

    return res;
  }

  // Converte numericamente un punteggio confrontando con il tiro successivo
  private static int convert(char previous, char current) {
    if (current == '/') return 10 - (previous - '0');
    else if (current == 'X') return 10;
    else return (current - '0');
  }
}
