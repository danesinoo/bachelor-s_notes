package it.unipd.pdp2022.bowling;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/** Un Frame non completato */
interface Score {
  default Stream<Score> pins(int pins) {
    return Stream.of(this);
  }

  default boolean done() {
    return false;
  }

  default Score next(int frame) {
    return frame < 8 ? new Empty(frame + 1) : new LastFrame();
  }
}

/** Frame completato */
interface DoneScore extends Score {
  @Override
  default boolean done() {
    return true;
  }

  int score();
}

// Frame vuoto - punto di partenza
record Empty(int frame) implements Score {
  @Override
  public Stream<Score> pins(int pins) {
    return pins < 10 ? Stream.of(new One(frame, pins)) : Stream.of(new Strike(frame), next(frame));
  }
}

// Gestione speciale dell'ultimo frame
record LastFrame() implements Score {
  @Override
  public Stream<Score> pins(int pins) {
    return Stream.of(new LastFrameOne(pins));
  }
}

// Primo tiro dell'ultimo frame
record LastFrameOne(int first) implements Score {
  @Override
  public Stream<Score> pins(int pins) {
    return Stream.of(
        (first == 10 || first + pins == 10)
            ? new LastFrameLong(first + pins)
            : new LastFrameDone(first + pins));
  }
}

// Secondo tiro di un ultimo frame da tre tiri
record LastFrameLong(int first) implements Score {
  @Override
  public Stream<Score> pins(int pins) {
    return Stream.of(new LastFrameDone(first + pins));
  }
}

// Ultimo frame completato
record LastFrameDone(int total) implements DoneScore {
  @Override
  public int score() {
    return total;
  }
}

// Primo tiro di un frame
record One(int frame, int first) implements Score {
  @Override
  public Stream<Score> pins(int pins) {
    return first + pins < 10
        ? Stream.of(new Frame(frame, first + pins), next(frame))
        : Stream.of(new Spare(frame), next(frame));
  }
}

// Frame completato
record Frame(int frame, int total) implements DoneScore {
  @Override
  public int score() {
    return total;
  }
}

// Frame completato con uno Spare
record Spare(int frame) implements Score {
  @Override
  public Stream<Score> pins(int pins) {
    return Stream.of(new SpareTotal(frame, pins));
  }
}

// Spare completamente totalizzato
record SpareTotal(int frame, int pins) implements DoneScore {
  @Override
  public int score() {
    return 10 + pins;
  }
}

// Frame completato con uno strike
record Strike(int frame) implements Score {
  @Override
  public Stream<Score> pins(int pins) {
    return Stream.of(new StrikePlus(frame, pins));
  }
}

// Primo tiro bonus di uno strike
record StrikePlus(int frame, int first) implements Score {
  @Override
  public Stream<Score> pins(int pins) {
    return Stream.of(new StrikeTotal(frame, first + pins));
  }
}

// Strike completamente totalizzato
record StrikeTotal(int frame, int pins) implements DoneScore {
  @Override
  public int score() {
    return 10 + pins;
  }
}

// Stato del gioco
class Status {

  List<DoneScore> completed = new ArrayList<>();
  // frame in corso di valutazione
  List<Score> current = List.of(new Empty(0));

  void add(int pins) {
    // notifico un tiro ad ognuno dei frame in valutazione; ottengo i nuovi frame da valutare
    Map<Boolean, List<Score>> next =
        current.stream().flatMap(c -> c.pins(pins)).collect(Collectors.groupingBy(Score::done));
    // aggiungo i frame completati alla lista del punteggio
    next.getOrDefault(Boolean.TRUE, List.of()).stream()
        .map(s -> (DoneScore) s)
        .forEachOrdered(completed::add);
    // i frame non completati diventano il nuovo stato corrente
    current = next.getOrDefault(Boolean.FALSE, List.of());
  }

  int score() {
    return completed.stream().mapToInt(DoneScore::score).sum();
  }
}

/**
 * Bowling Kata
 *
 * <p>Approccio "ADT"
 */
public class BowlingGame2 {

  Status status;

  public BowlingGame2(String frames) {
    status = new Status();
    for (int i : BowlingGame.read(frames)) status.add(i);
  }

  public int score() {
    return status.score();
  }
}
