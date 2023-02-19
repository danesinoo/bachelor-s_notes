#include <list>
#include <vector>
typedef unsigned int uint;

class File {
private:
  uint s;
  bool p;

public:
  File(uint size, bool isPublic) : s(size), p(isPublic) {}
  File() : File(0, false){};
  uint get_size() const { return s; }
  uint isPublic() const { return p; }
  virtual ~File() = default;
};

class Audio : public File {
private:
  bool l;

public:
  Audio(bool isLossy, uint size, bool isPublic)
      : File(size, isPublic), l(isLossy) {}
  Audio() : Audio(false, 0, false) {}
  bool isLossy() const { return l; }
};

class mp3 : public Audio {
public:
  mp3(uint size, bool isPublic) : Audio(true, size, isPublic){};
};

class Video : public File {
private:
  uint fr;

public:
  Video(uint framerate, uint size, bool isPublic)
      : fr(framerate), File(size, isPublic) {}

  Video() : fr(0){};

  uint get_framerate() const { return fr; }
};

enum Exc { NotAnAudio = 1, VideoMissing = 0 };

class QooqleDrive {
private:
  uint s;
  std::vector<const File *> vec;

public:
  QooqleDrive(uint size, std::vector<const File *> v) : s(size), vec(v) {}
  QooqleDrive() : s(0) {}

  Audio uploadFile(File &f) {
    Audio *audio = dynamic_cast<Audio *>(&f);
    if (audio && s > audio->get_size()) {
      s -= audio->get_size();
      vec.push_back(new File(f));
      return *audio;
    }
    throw NotAnAudio;
  }

  std::list<Audio *> audioCopy() const {
    std::list<Audio *> list;
    Audio *audio;
    std::for_each(vec.begin(), vec.end(), [&list, &audio](auto file) {
      audio = dynamic_cast<Audio *>(const_cast<File *>(file));
      if (audio && audio->isLossy())
        list.push_back(audio);
    });
    return list;
  }

  Video *minVideo(uint fr) const {
    Video *video, *min_video = nullptr;
    std::for_each(vec.begin(), vec.end(), [&, fr](auto file) {
      video = dynamic_cast<Video *>(const_cast<File *>(file));
      if (video && video->get_framerate() > fr && min_video &&
          min_video->get_size() > video->get_size())
        min_video = video;
    });
    if (min_video)
      return min_video;
    throw VideoMissing;
  }
};
